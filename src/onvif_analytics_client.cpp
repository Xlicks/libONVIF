//
// Created by licks on 25-7-3.
//

#include "onvif_analytics_client.h"
#include "soapAnalyticsDeviceBindingProxy.h"

struct OnvifAnalyticsClientImplementation
{
    explicit OnvifAnalyticsClientImplementation(OnvifAnalyticsClient *analytics_client_ptr) : ac_ptr(analytics_client_ptr),
        analytics_proxy(ac_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(analytics_proxy.soap, SoapContext::GetDefaultNamespaces());
        ac_ptr->GetContext()->Release();
    }
    OnvifAnalyticsClient *ac_ptr;
    AnalyticsDeviceBindingProxy analytics_proxy;
};

OnvifAnalyticsClient::OnvifAnalyticsClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
        : OnvifClient(endpoint, std::move(shared_ctx)),
          impl_(new (std::nothrow) OnvifAnalyticsClientImplementation(this))
{
}

OnvifAnalyticsClient::~OnvifAnalyticsClient()
{
    delete impl_;
}

Response<_tad__GetServiceCapabilitiesResponse> OnvifAnalyticsClient::GetServiceCapabilities(
    Request<_tad__GetServiceCapabilities>& request) const
{
    _tad__GetServiceCapabilitiesResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetServiceCapabilities(GetEndpoint().c_str(), !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__DeleteAnalyticsEngineControlResponse> OnvifAnalyticsClient::DeleteAnalyticsEngineControl(
    Request<_tad__DeleteAnalyticsEngineControl>& request) const
{
    _tad__DeleteAnalyticsEngineControlResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.DeleteAnalyticsEngineControl(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__DeleteAnalyticsEngineControlResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__CreateAnalyticsEngineControlResponse> OnvifAnalyticsClient::CreateAnalyticsEngineControl(
    Request<_tad__CreateAnalyticsEngineControl>& request) const
{
    _tad__CreateAnalyticsEngineControlResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.CreateAnalyticsEngineControl(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__CreateAnalyticsEngineControlResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__SetAnalyticsEngineControlResponse> OnvifAnalyticsClient::SetAnalyticsEngineControl(
    Request<_tad__SetAnalyticsEngineControl>& request) const
{
    _tad__SetAnalyticsEngineControlResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.SetAnalyticsEngineControl(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__SetAnalyticsEngineControlResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEngineControlResponse> OnvifAnalyticsClient::GetAnalyticsEngineControl(
    Request<_tad__GetAnalyticsEngineControl>& request) const
{
    _tad__GetAnalyticsEngineControlResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngineControl(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEngineControlResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEngineControlsResponse> OnvifAnalyticsClient::GetAnalyticsEngineControls(
    Request<_tad__GetAnalyticsEngineControls>& request) const
{
    _tad__GetAnalyticsEngineControlsResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngineControls(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEngineControlsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEngineResponse> OnvifAnalyticsClient::GetAnalyticsEngine(
    Request<_tad__GetAnalyticsEngine>& request) const
{
    _tad__GetAnalyticsEngineResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngine(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEngineResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEnginesResponse> OnvifAnalyticsClient::GetAnalyticsEngines(
    Request<_tad__GetAnalyticsEngines>& request) const
{
    _tad__GetAnalyticsEnginesResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngines(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEnginesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__SetVideoAnalyticsConfigurationResponse> OnvifAnalyticsClient::SetVideoAnalyticsConfiguration(
    Request<_tad__SetVideoAnalyticsConfiguration>& request) const
{
    _tad__SetVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.SetVideoAnalyticsConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__SetVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEngineInputResponse> OnvifAnalyticsClient::GetAnalyticsEngineInput(
    Request<_tad__GetAnalyticsEngineInput>& request) const
{
    _tad__GetAnalyticsEngineInputResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngineInput(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEngineInputResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsEngineInputsResponse> OnvifAnalyticsClient::GetAnalyticsEngineInputs(
    Request<_tad__GetAnalyticsEngineInputs>& request) const
{
    _tad__GetAnalyticsEngineInputsResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsEngineInputs(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsEngineInputsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsDeviceStreamUriResponse> OnvifAnalyticsClient::GetAnalyticsDeviceStreamUri(
    Request<_tad__GetAnalyticsDeviceStreamUri>& request) const
{
    _tad__GetAnalyticsDeviceStreamUriResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsDeviceStreamUri(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsDeviceStreamUriResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetVideoAnalyticsConfigurationResponse> OnvifAnalyticsClient::GetVideoAnalyticsConfiguration(
    Request<_tad__GetVideoAnalyticsConfiguration>& request) const
{
    _tad__GetVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetVideoAnalyticsConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__CreateAnalyticsEngineInputsResponse> OnvifAnalyticsClient::CreateAnalyticsEngineInputs(
    Request<_tad__CreateAnalyticsEngineInputs>& request) const
{
    _tad__CreateAnalyticsEngineInputsResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.CreateAnalyticsEngineInputs(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__CreateAnalyticsEngineInputsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__DeleteAnalyticsEngineInputsResponse> OnvifAnalyticsClient::DeleteAnalyticsEngineInputs(
    Request<_tad__DeleteAnalyticsEngineInputs>& request) const
{
    _tad__DeleteAnalyticsEngineInputsResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.DeleteAnalyticsEngineInputs(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__DeleteAnalyticsEngineInputsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}

Response<_tad__GetAnalyticsStateResponse> OnvifAnalyticsClient::GetAnalyticsState(
    Request<_tad__GetAnalyticsState>& request) const
{
    _tad__GetAnalyticsStateResponse response_object;
    const auto soap_ctx_ptr = AcquireContext();
    do
    {
        impl_->analytics_proxy.GetAnalyticsState(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ctx_ptr));
    auto response = Response<_tad__GetAnalyticsStateResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx_ptr);
    return response.Build();
}
