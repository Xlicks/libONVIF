//
// Created by licks on 25-7-3.
//

#include "onvif_imaging_client.h"
#include "soapImagingBindingProxy.h"

struct OnvifImagingClientImplementation
{
    explicit OnvifImagingClientImplementation(OnvifImagingClient* ic_ptr)
        : image_client_ptr(ic_ptr),
          image_binding_proxy(ic_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(image_binding_proxy.soap, SoapContext::GetDefaultNamespaces());
        ic_ptr->GetContext()->Release();
    }
    OnvifImagingClient* image_client_ptr;
    ImagingBindingProxy image_binding_proxy;
};


OnvifImagingClient::OnvifImagingClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
    : OnvifClient(endpoint, std::move(shared_ctx)),
      impl_(new (std::nothrow) OnvifImagingClientImplementation(this))
{
}

OnvifImagingClient::~OnvifImagingClient()
{
    delete impl_;
}

Response<_timg__GetServiceCapabilitiesResponse> OnvifImagingClient::GetServiceCapabilities(
    Request<_timg__GetServiceCapabilities>& request) const
{
    _timg__GetServiceCapabilitiesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetServiceCapabilities(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr,
                                                          &request,
                                                          response_object);
    } while (ReTry(soap_ctx));
    auto response = Response<_timg__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetImagingSettingsResponse> OnvifImagingClient::GetImagingSettings(
    Request<_timg__GetImagingSettings>& request) const
{
    _timg__GetImagingSettingsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetImagingSettings(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                       &request,
                                                       response_object);
    } while (ReTry(soap_ctx));
    auto response = Response<_timg__GetImagingSettingsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__SetImagingSettingsResponse> OnvifImagingClient::SetImagingSettings(
    Request<_timg__SetImagingSettings>& request) const
{
    _timg__SetImagingSettingsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.SetImagingSettings(GetEndpoint().c_str(),
                                                      !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                       &request,
                                                       response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__SetImagingSettingsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetOptionsResponse> OnvifImagingClient::GetOptions(Request<_timg__GetOptions>& rRequest) const
{
    _timg__GetOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetOptions(GetEndpoint().c_str(),
                                              !rRequest.GetSoapAction().empty()? rRequest.GetSoapAction().c_str() : nullptr,
                                               &rRequest,
                                               response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__GetOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__MoveResponse> OnvifImagingClient::Move(Request<_timg__Move>& request) const
{
    _timg__MoveResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.Move(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                         &request,
                                         response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__MoveResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__StopResponse> OnvifImagingClient::Stop(Request<_timg__Stop>& request) const
{
    _timg__StopResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.Stop(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                         &request,
                                         response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__StopResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetStatusResponse> OnvifImagingClient::GetStatus(Request<_timg__GetStatus>& request) const
{
    _timg__GetStatusResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetStatus(GetEndpoint().c_str(),
                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                              &request,
                                              response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__GetStatusResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetMoveOptionsResponse> OnvifImagingClient::GetMoveOptions(Request<_timg__GetMoveOptions>& request) const
{
    _timg__GetMoveOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetMoveOptions(GetEndpoint().c_str(),
                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__GetMoveOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetPresetsResponse> OnvifImagingClient::GetPresets(Request<_timg__GetPresets>& request) const
{
    _timg__GetPresetsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetPresets(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                               &request,
                                               response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__GetPresetsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__GetCurrentPresetResponse> OnvifImagingClient::GetCurrentPreset(
    Request<_timg__GetCurrentPreset>& request) const
{
    _timg__GetCurrentPresetResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.GetCurrentPreset(GetEndpoint().c_str(),
                                                  !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                    &request,
                                                    response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_timg__GetCurrentPresetResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_timg__SetCurrentPresetResponse> OnvifImagingClient::SetCurrentPreset(
    Request<_timg__SetCurrentPreset>& request) const
{
    _timg__SetCurrentPresetResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->image_binding_proxy.SetCurrentPreset(GetEndpoint().c_str(),
                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                    &request,
                                                    response_object);
    }  while (ReTry(soap_ctx));
    auto response = Response<_timg__SetCurrentPresetResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}
