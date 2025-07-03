//
// Created by licks on 25-7-3.
//

#include "onvif_display_client.h"
#include "soapDisplayBindingProxy.h"

struct OnvifDisplayClientImplementation
{
    explicit OnvifDisplayClientImplementation(OnvifDisplayClient* display_client_ptr)
        : display_client_ptr(display_client_ptr),
          display_proxy(display_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(display_proxy.soap, SoapContext::GetDefaultNamespaces());
        display_client_ptr->GetContext()->Release();
    }

    OnvifDisplayClient* display_client_ptr;
    DisplayBindingProxy display_proxy;
};

OnvifDisplayClient::OnvifDisplayClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
    : OnvifClient(endpoint, std::move(shared_ctx)), impl_( new (std::nothrow) OnvifDisplayClientImplementation(this))
{
}

OnvifDisplayClient::~OnvifDisplayClient()
{
    delete impl_;
}

Response<_tls__GetServiceCapabilitiesResponse> OnvifDisplayClient::GetServiceCapabilities(
    Request<_tls__GetServiceCapabilities>& request) const
{
    _tls__GetServiceCapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.GetServiceCapabilities(GetEndpoint().c_str(), !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__GetLayoutResponse> OnvifDisplayClient::GetLayout(Request<_tls__GetLayout>& request) const
{
    _tls__GetLayoutResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.GetLayout(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__GetLayoutResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__SetLayoutResponse> OnvifDisplayClient::SetLayout(Request<_tls__SetLayout>& request) const
{
    _tls__SetLayoutResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.SetLayout(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__SetLayoutResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__GetDisplayOptionsResponse> OnvifDisplayClient::GetDisplayOptions(
    Request<_tls__GetDisplayOptions>& request) const
{
    _tls__GetDisplayOptionsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.GetDisplayOptions(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__GetDisplayOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__GetPaneConfigurationsResponse> OnvifDisplayClient::GetPaneConfigurations(
    Request<_tls__GetPaneConfigurations>& request) const
{
    _tls__GetPaneConfigurationsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.GetPaneConfigurations(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__GetPaneConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__GetPaneConfigurationResponse> OnvifDisplayClient::GetPaneConfiguration(
    Request<_tls__GetPaneConfiguration>& request) const
{
    _tls__GetPaneConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.GetPaneConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__GetPaneConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__SetPaneConfigurationsResponse> OnvifDisplayClient::SetPaneConfigurations(
    Request<_tls__SetPaneConfigurations>& request) const
{
    _tls__SetPaneConfigurationsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.SetPaneConfigurations(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__SetPaneConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__SetPaneConfigurationResponse> OnvifDisplayClient::SetPaneConfiguration(
    Request<_tls__SetPaneConfiguration>& request) const
{
    _tls__SetPaneConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.SetPaneConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__SetPaneConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__CreatePaneConfigurationResponse> OnvifDisplayClient::CreatePaneConfiguration(
    Request<_tls__CreatePaneConfiguration>& request) const
{
    _tls__CreatePaneConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.CreatePaneConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__CreatePaneConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tls__DeletePaneConfigurationResponse> OnvifDisplayClient::DeletePaneConfiguration(
    Request<_tls__DeletePaneConfiguration>& request) const
{
    _tls__DeletePaneConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->display_proxy.DeletePaneConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tls__DeletePaneConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}
