//
// Created by licks on 24-7-1.
//

#include "onvif_client.h"
#include <mutex>
#include <atomic>
#include <utility>
/*
   Avoid "unused parameter" warnings
*/
#define STD_UNUSED(x) (void)(x);


struct ClientPrivate
{
    ClientPrivate(OnvifClient* client, std::string endpoint, std::shared_ptr<SoapContext> soap_ctx)
        : client_ptr(client), ctx_sptr(std::move(soap_ctx)), endpoint(std::move(endpoint)), context_owns(false)
    {}
    OnvifClient *client_ptr;
    std::shared_ptr<SoapContext> ctx_sptr;
    std::string endpoint;
    std::mutex mutex;
    std::atomic_bool context_owns;
};

OnvifClient::OnvifClient(const std::string& endpoint, std::shared_ptr<SoapContext> soap_ctx)
    : impl_(new (std::nothrow) ClientPrivate(this, endpoint, std::move(soap_ctx)))
{
}

OnvifClient::~OnvifClient()
{
    delete impl_;
}

void OnvifClient::SetAuth(const std::string& user_name, const std::string& password, const AuthMode mode) const
{
    AuthHandlerMode authMode;
    switch (mode)
    {
    case NO_AUTH:
        authMode = AuthHandlerMode::NO_AUTH;
        break;
    case HTTP_DIGEST:
        authMode = AuthHandlerMode::HTTP_DIGEST;
        break;
    case WS_USERNAME_TOKEN:
        authMode = AuthHandlerMode::WS_USERNAME_TOKEN;
        break;
    case BOTH:
        authMode = AuthHandlerMode::BOTH;
        break;
    case AUTO:
    default:
        authMode = AuthHandlerMode::AUTO;
        break;
    }
    impl_->ctx_sptr->SetAuth(user_name, password, authMode);
}

void OnvifClient::DisableAuth() const
{
    return impl_->ctx_sptr->DisableAuth();
}

std::shared_ptr<SoapContext> OnvifClient::GetContext() const
{
    return impl_->ctx_sptr;
}

std::string OnvifClient::GetFaultString() const
{
    return impl_->ctx_sptr->GetFaultString();
}

std::string OnvifClient::GetFaultDetail() const
{
    return impl_->ctx_sptr->GetFaultDetail();
}

std::string OnvifClient::GetEndpoint() const
{
    std::lock_guard lock(impl_->mutex);
    return impl_->endpoint;
}

void OnvifClient::SetEndpoint(const std::string& endpoint) const
{
    std::lock_guard lock(impl_->mutex);
    impl_->endpoint = endpoint;
}

void OnvifClient::CancelRequest() const
{
    if (impl_->context_owns)
    {
        impl_->ctx_sptr->ForceSocketClose();
    }
}

soap* OnvifClient::AcquireContext() const
{
    const auto ctx = impl_->ctx_sptr->Acquire();
    if (ctx)
    {
        impl_->ctx_sptr->RestoreAuthData();
        impl_->context_owns = true;
    }
    return ctx;
}

soap* OnvifClient::TryAcquireContext(const int timeoutMs/* = 0*/) const
{
    const auto ctx = impl_->ctx_sptr->TryAcquire(timeoutMs);
    if (ctx)
    {
        impl_->ctx_sptr->RestoreAuthData();
        impl_->context_owns = true;
    }
    return ctx;
}

void OnvifClient::ReleaseContext(soap* ctx) const
{
    if (ctx)
    {
        impl_->context_owns = false;
        soap_destroy(ctx);
        soap_end(ctx);
        impl_->ctx_sptr->Release();
    }
}

int OnvifClient::ReTry(const soap* ctx) const
{
    STD_UNUSED(ctx);
    auto retry = false;
    if (impl_->ctx_sptr->IsAuthFault()) retry = impl_->ctx_sptr->ProcessAuthFaultAndRetry();
    if (retry)
    {
        impl_->ctx_sptr->RestoreAuthData();
    }
    return retry;
}
