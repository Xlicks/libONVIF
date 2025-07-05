//
// Created by licks on 25-7-3.
//

#include "onvif_media2_client.h"
#include "soapMedia2BindingProxy.h"

struct OnvifMedia2ClientImplementation
{
    explicit OnvifMedia2ClientImplementation(OnvifMedia2Client* media_client_ptr)
        : media_client_ptr(media_client_ptr),
          media_binding_proxy(media_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(media_binding_proxy.soap, SoapContext::GetDefaultNamespaces());
        media_client_ptr->GetContext()->Release();
    }
    OnvifMedia2Client* media_client_ptr;
    Media2BindingProxy media_binding_proxy;
};

OnvifMedia2Client::OnvifMedia2Client(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
    : OnvifClient(endpoint, std::move(shared_ctx)),
      impl_(new (std::nothrow) OnvifMedia2ClientImplementation(this))
{
}

OnvifMedia2Client::~OnvifMedia2Client()
{
    delete impl_;
}

Response<_ns1__GetServiceCapabilitiesResponse> OnvifMedia2Client::GetServiceCapabilities(
    Request<_ns1__GetServiceCapabilities>& request) const
{
    _ns1__GetServiceCapabilitiesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetServiceCapabilities(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                           &request,
                                                           response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__CreateProfileResponse> OnvifMedia2Client::CreateProfile(Request<_ns1__CreateProfile>& request) const
{
    _ns1__CreateProfileResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.CreateProfile(GetEndpoint().c_str(),
                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__CreateProfileResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetProfilesResponse> OnvifMedia2Client::GetProfiles(Request<_ns1__GetProfiles>& request) const
{
    _ns1__GetProfilesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetProfiles(GetEndpoint().c_str(),
                                               !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                 &request,
                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetProfilesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__AddConfigurationResponse> OnvifMedia2Client::AddConfiguration(Request<_ns1__AddConfiguration>& request) const
{
    _ns1__AddConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddConfiguration(GetEndpoint().c_str(),
                                                   !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                     &request,
                                                     response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__AddConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__RemoveConfigurationResponse> OnvifMedia2Client::RemoveConfiguration(
    Request<_ns1__RemoveConfiguration>& request) const
{
    _ns1__RemoveConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveConfiguration(GetEndpoint().c_str(),
                                                     !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                        &request,
                                                        response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__RemoveConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__DeleteProfileResponse> OnvifMedia2Client::DeleteProfile(Request<_ns1__DeleteProfile>& request) const
{
    _ns1__DeleteProfileResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.DeleteProfile(GetEndpoint().c_str(),
                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                    &request,
                                                    response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__DeleteProfileResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoSourceConfigurationsResponse> OnvifMedia2Client::GetVideoSourceConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetVideoSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceConfigurations(GetEndpoint().c_str(),
                                                               !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoEncoderConfigurationsResponse> OnvifMedia2Client::GetVideoEncoderConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetVideoEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderConfigurations(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioSourceConfigurationsResponse> OnvifMedia2Client::GetAudioSourceConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSourceConfigurations(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioEncoderConfigurationsResponse> OnvifMedia2Client::GetAudioEncoderConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioEncoderConfigurations(GetEndpoint().c_str(),
                                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAnalyticsConfigurationsResponse> OnvifMedia2Client::GetAnalyticsConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAnalyticsConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAnalyticsConfigurations(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                             &request,
                                                             response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAnalyticsConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetMetadataConfigurationsResponse> OnvifMedia2Client::GetMetadataConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetMetadataConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMetadataConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                             &request,
                                                             response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetMetadataConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioOutputConfigurationsResponse> OnvifMedia2Client::GetAudioOutputConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioOutputConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputConfigurations(GetEndpoint().c_str(),
                                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioOutputConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioDecoderConfigurationsResponse> OnvifMedia2Client::GetAudioDecoderConfigurations(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioDecoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioDecoderConfigurations(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioDecoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetVideoSourceConfiguration(
    Request<_ns1__SetVideoSourceConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoSourceConfiguration(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetVideoEncoderConfiguration(
    Request<_ns1__SetVideoEncoderConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoEncoderConfiguration(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetAudioSourceConfiguration(
    Request<_ns1__SetAudioSourceConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioSourceConfiguration(GetEndpoint().c_str(),
                                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetAudioEncoderConfiguration(
    Request<_ns1__SetAudioEncoderConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioEncoderConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetMetadataConfiguration(
    Request<_ns1__SetMetadataConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetMetadataConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetAudioOutputConfiguration(
    Request<_ns1__SetAudioOutputConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioOutputConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetAudioDecoderConfiguration(
    Request<_ns1__SetAudioDecoderConfiguration>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioDecoderConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoSourceConfigurationOptionsResponse> OnvifMedia2Client::GetVideoSourceConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetVideoSourceConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceConfigurationOptions(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoSourceConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoEncoderConfigurationOptionsResponse> OnvifMedia2Client::GetVideoEncoderConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetVideoEncoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderConfigurationOptions(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoEncoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioSourceConfigurationOptionsResponse> OnvifMedia2Client::GetAudioSourceConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioSourceConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSourceConfigurationOptions(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioSourceConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioEncoderConfigurationOptionsResponse> OnvifMedia2Client::GetAudioEncoderConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioEncoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioEncoderConfigurationOptions(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioEncoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetMetadataConfigurationOptionsResponse> OnvifMedia2Client::GetMetadataConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetMetadataConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMetadataConfigurationOptions(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetMetadataConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioOutputConfigurationOptionsResponse> OnvifMedia2Client::GetAudioOutputConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioOutputConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputConfigurationOptions(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioOutputConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetAudioDecoderConfigurationOptionsResponse> OnvifMedia2Client::GetAudioDecoderConfigurationOptions(
    Request<ns1__GetConfiguration>& request) const
{
    _ns1__GetAudioDecoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioDecoderConfigurationOptions(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetAudioDecoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoEncoderInstancesResponse> OnvifMedia2Client::GetVideoEncoderInstances(
    Request<_ns1__GetVideoEncoderInstances>& request) const
{
    _ns1__GetVideoEncoderInstancesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderInstances(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoEncoderInstancesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetStreamUriResponse> OnvifMedia2Client::GetStreamUri(Request<_ns1__GetStreamUri>& request) const
{
    _ns1__GetStreamUriResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetStreamUri(GetEndpoint().c_str(),
                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetStreamUriResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::StartMulticastStreaming(
    Request<ns1__StartStopMulticastStreaming>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.StartMulticastStreaming(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::StopMulticastStreaming(
    Request<ns1__StartStopMulticastStreaming>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.StopMulticastStreaming(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                            &request,
                                                            response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__SetSynchronizationPointResponse> OnvifMedia2Client::SetSynchronizationPoint(
    Request<_ns1__SetSynchronizationPoint>& request) const
{
    _ns1__SetSynchronizationPointResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetSynchronizationPoint(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                 &request,
                                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__SetSynchronizationPointResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetSnapshotUriResponse> OnvifMedia2Client::GetSnapshotUri(Request<_ns1__GetSnapshotUri>& request) const
{
    _ns1__GetSnapshotUriResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetSnapshotUri(GetEndpoint().c_str(),
                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                     &request,
                                                     response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetSnapshotUriResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetVideoSourceModesResponse> OnvifMedia2Client::GetVideoSourceModes(
    Request<_ns1__GetVideoSourceModes>& request) const
{
    _ns1__GetVideoSourceModesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceModes(GetEndpoint().c_str(),
                                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                         &request,
                                                         response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetVideoSourceModesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__SetVideoSourceModeResponse> OnvifMedia2Client::SetVideoSourceMode(
    Request<_ns1__SetVideoSourceMode>& request) const
{
    _ns1__SetVideoSourceModeResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoSourceMode(GetEndpoint().c_str(),
                                                     !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                           &request,
                                                           response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__SetVideoSourceModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetOSDsResponse> OnvifMedia2Client::GetOSDs(Request<_ns1__GetOSDs>& request) const
{
    _ns1__GetOSDsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetOSDs(GetEndpoint().c_str(),
                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetOSDsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetOSDOptionsResponse> OnvifMedia2Client::GetOSDOptions(Request<_ns1__GetOSDOptions>& request) const
{
    _ns1__GetOSDOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetOSDOptions(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                      &request,
                                                      response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetOSDOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetOSD(Request<_ns1__SetOSD>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetOSD(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                 &request,
                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__CreateOSDResponse> OnvifMedia2Client::CreateOSD(Request<_ns1__CreateOSD>& request) const
{
    _ns1__CreateOSDResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.CreateOSD(GetEndpoint().c_str(),
                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                   &request,
                                                   response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__CreateOSDResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::DeleteOSD(Request<_ns1__DeleteOSD>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.DeleteOSD(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                   &request,
                                                   response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetMasksResponse> OnvifMedia2Client::GetMasks(Request<_ns1__GetMasks>& request) const
{
    _ns1__GetMasksResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMasks(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetMasksResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__GetMaskOptionsResponse> OnvifMedia2Client::GetMaskOptions(Request<_ns1__GetMaskOptions>& request) const
{
    _ns1__GetMaskOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMaskOptions(GetEndpoint().c_str(),
                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                  &request,
                                                  response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__GetMaskOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::SetMask(Request<_ns1__SetMask>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetMask(GetEndpoint().c_str(),
                                      !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                 &request,
                                                 response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_ns1__CreateMaskResponse> OnvifMedia2Client::CreateMask(Request<_ns1__CreateMask>& request) const
{
    _ns1__CreateMaskResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.CreateMask(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                   &request,
                                                   response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_ns1__CreateMaskResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<ns1__SetConfigurationResponse> OnvifMedia2Client::DeleteMask(Request<_ns1__DeleteMask>& request) const
{
    ns1__SetConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.DeleteMask(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                   &request,
                                                   response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<ns1__SetConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}
