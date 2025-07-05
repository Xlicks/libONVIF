//
// Created by licks on 25-7-3.
//

#include "onvif_media_client.h"
#include "soapMediaBindingProxy.h"

struct OnvifMediaClientImplementation
{
    explicit OnvifMediaClientImplementation(OnvifMediaClient* mc_ptr)
        : media_client_ptr(mc_ptr),
          media_binding_proxy(media_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(media_binding_proxy.soap, SoapContext::GetDefaultNamespaces());
        media_client_ptr->GetContext()->Release();
    }

    OnvifMediaClient* media_client_ptr;
    MediaBindingProxy media_binding_proxy;
};

OnvifMediaClient::OnvifMediaClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
    : OnvifClient(endpoint, std::move(shared_ctx)),
      impl_(new (std::nothrow) OnvifMediaClientImplementation(this))
{
}

OnvifMediaClient::~OnvifMediaClient()
{
    delete impl_;
}

Response<_trt__GetServiceCapabilitiesResponse> OnvifMediaClient::GetServiceCapabilities(
    Request<_trt__GetServiceCapabilities>& request) const
{
    _trt__GetServiceCapabilitiesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetServiceCapabilities(GetEndpoint().c_str(),
                                                !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoSourcesResponse> OnvifMediaClient::GetVideoSources(Request<_trt__GetVideoSources>& request) const
{
    _trt__GetVideoSourcesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSources(GetEndpoint().c_str(),
                                               !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoSourcesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioSourcesResponse> OnvifMediaClient::GetAudioSources(Request<_trt__GetAudioSources>& request) const
{
    _trt__GetAudioSourcesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSources(GetEndpoint().c_str(),
                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioSourcesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioOutputsResponse> OnvifMediaClient::GetAudioOutputs(Request<_trt__GetAudioOutputs>& request) const
{
    _trt__GetAudioOutputsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputs(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioOutputsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__CreateProfileResponse> OnvifMediaClient::CreateProfile(Request<_trt__CreateProfile>& request) const
{
    _trt__CreateProfileResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.CreateProfile(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__CreateProfileResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetProfileResponse> OnvifMediaClient::GetProfile(Request<_trt__GetProfile>& request) const
{
    _trt__GetProfileResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetProfile(GetEndpoint().c_str(),
                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetProfileResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetProfilesResponse> OnvifMediaClient::GetProfiles(Request<_trt__GetProfiles>& request) const
{
    _trt__GetProfilesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetProfiles(GetEndpoint().c_str(),
                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetProfilesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddVideoEncoderConfigurationResponse> OnvifMediaClient::AddVideoEncoderConfiguration(
    Request<_trt__AddVideoEncoderConfiguration>& request) const
{
    _trt__AddVideoEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddVideoEncoderConfiguration(GetEndpoint().c_str(),
                                                               !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddVideoEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddVideoSourceConfigurationResponse> OnvifMediaClient::AddVideoSourceConfiguration(
    Request<_trt__AddVideoSourceConfiguration>& request) const
{
    _trt__AddVideoSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddVideoSourceConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddVideoSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddAudioEncoderConfigurationResponse> OnvifMediaClient::AddAudioEncoderConfiguration(
    Request<_trt__AddAudioEncoderConfiguration>& request) const
{
    _trt__AddAudioEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddAudioEncoderConfiguration(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddAudioEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddAudioSourceConfigurationResponse> OnvifMediaClient::AddAudioSourceConfiguration(
    Request<_trt__AddAudioSourceConfiguration>& request) const
{
    _trt__AddAudioSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddAudioSourceConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddAudioSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddPTZConfigurationResponse> OnvifMediaClient::AddPTZConfiguration(
    Request<_trt__AddPTZConfiguration>& request) const
{
    _trt__AddPTZConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddPTZConfiguration(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddPTZConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddVideoAnalyticsConfigurationResponse> OnvifMediaClient::AddVideoAnalyticsConfiguration(
    Request<_trt__AddVideoAnalyticsConfiguration>& request) const
{
    _trt__AddVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddVideoAnalyticsConfiguration(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddMetadataConfigurationResponse> OnvifMediaClient::AddMetadataConfiguration(
    Request<_trt__AddMetadataConfiguration>& request) const
{
    _trt__AddMetadataConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddMetadataConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddMetadataConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddAudioOutputConfigurationResponse> OnvifMediaClient::AddAudioOutputConfiguration(
    Request<_trt__AddAudioOutputConfiguration>& request) const
{
    _trt__AddAudioOutputConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddAudioOutputConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddAudioOutputConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__AddAudioDecoderConfigurationResponse> OnvifMediaClient::AddAudioDecoderConfiguration(
    Request<_trt__AddAudioDecoderConfiguration>& request) const
{
    _trt__AddAudioDecoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.AddAudioDecoderConfiguration(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__AddAudioDecoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveVideoEncoderConfigurationResponse> OnvifMediaClient::RemoveVideoEncoderConfiguration(
    Request<_trt__RemoveVideoEncoderConfiguration>& request) const
{
    _trt__RemoveVideoEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveVideoEncoderConfiguration(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveVideoEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveVideoSourceConfigurationResponse> OnvifMediaClient::RemoveVideoSourceConfiguration(
    Request<_trt__RemoveVideoSourceConfiguration>& request) const
{
    _trt__RemoveVideoSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveVideoSourceConfiguration(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveVideoSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveAudioEncoderConfigurationResponse> OnvifMediaClient::RemoveAudioEncoderConfiguration(
    Request<_trt__RemoveAudioEncoderConfiguration>& request) const
{
    _trt__RemoveAudioEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveAudioEncoderConfiguration(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveAudioEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveAudioSourceConfigurationResponse> OnvifMediaClient::RemoveAudioSourceConfiguration(
    Request<_trt__RemoveAudioSourceConfiguration>& request) const
{
    _trt__RemoveAudioSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveAudioSourceConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveAudioSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemovePTZConfigurationResponse> OnvifMediaClient::RemovePTZConfiguration(
    Request<_trt__RemovePTZConfiguration>& request) const
{
    _trt__RemovePTZConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemovePTZConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemovePTZConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveVideoAnalyticsConfigurationResponse> OnvifMediaClient::RemoveVideoAnalyticsConfiguration(
    Request<_trt__RemoveVideoAnalyticsConfiguration>& request) const
{
    _trt__RemoveVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveVideoAnalyticsConfiguration(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveMetadataConfigurationResponse> OnvifMediaClient::RemoveMetadataConfiguration(
    Request<_trt__RemoveMetadataConfiguration>& request) const
{
    _trt__RemoveMetadataConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveMetadataConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveMetadataConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveAudioOutputConfigurationResponse> OnvifMediaClient::RemoveAudioOutputConfiguration(
    Request<_trt__RemoveAudioOutputConfiguration>& request) const
{
    _trt__RemoveAudioOutputConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveAudioOutputConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveAudioOutputConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__RemoveAudioDecoderConfigurationResponse> OnvifMediaClient::RemoveAudioDecoderConfiguration(
    Request<_trt__RemoveAudioDecoderConfiguration>& request) const
{
    _trt__RemoveAudioDecoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.RemoveAudioDecoderConfiguration(GetEndpoint().c_str(),
                                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__RemoveAudioDecoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__DeleteProfileResponse> OnvifMediaClient::DeleteProfile(Request<_trt__DeleteProfile>& request) const
{
    _trt__DeleteProfileResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.DeleteProfile(GetEndpoint().c_str(),
                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__DeleteProfileResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoSourceConfigurationsResponse> OnvifMediaClient::GetVideoSourceConfigurations(
    Request<_trt__GetVideoSourceConfigurations>& request) const
{
    _trt__GetVideoSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceConfigurations(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoEncoderConfigurationsResponse> OnvifMediaClient::GetVideoEncoderConfigurations(
    Request<_trt__GetVideoEncoderConfigurations>& request) const
{
    _trt__GetVideoEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderConfigurations(GetEndpoint().c_str(),
                                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioSourceConfigurationsResponse> OnvifMediaClient::GetAudioSourceConfigurations(
    Request<_trt__GetAudioSourceConfigurations>& request) const
{
    _trt__GetAudioSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSourceConfigurations(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioEncoderConfigurationsResponse> OnvifMediaClient::GetAudioEncoderConfigurations(
    Request<_trt__GetAudioEncoderConfigurations>& request) const
{
    _trt__GetAudioEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioEncoderConfigurations(GetEndpoint().c_str(),
                                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoAnalyticsConfigurationsResponse> OnvifMediaClient::GetVideoAnalyticsConfigurations(
    Request<_trt__GetVideoAnalyticsConfigurations>& request) const
{
    _trt__GetVideoAnalyticsConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoAnalyticsConfigurations(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoAnalyticsConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetMetadataConfigurationsResponse> OnvifMediaClient::GetMetadataConfigurations(
    Request<_trt__GetMetadataConfigurations>& request) const
{
    _trt__GetMetadataConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMetadataConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetMetadataConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioOutputConfigurationsResponse> OnvifMediaClient::GetAudioOutputConfigurations(
    Request<_trt__GetAudioOutputConfigurations>& request) const
{
    _trt__GetAudioOutputConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioOutputConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioDecoderConfigurationsResponse> OnvifMediaClient::GetAudioDecoderConfigurations(
    Request<_trt__GetAudioDecoderConfigurations>& request) const
{
    _trt__GetAudioDecoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioDecoderConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioDecoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoSourceConfigurationResponse> OnvifMediaClient::GetVideoSourceConfiguration(
    Request<_trt__GetVideoSourceConfiguration>& request) const
{
    _trt__GetVideoSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceConfiguration(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoEncoderConfigurationResponse> OnvifMediaClient::GetVideoEncoderConfiguration(
    Request<_trt__GetVideoEncoderConfiguration>& request) const
{
    _trt__GetVideoEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioSourceConfigurationResponse> OnvifMediaClient::GetAudioSourceConfiguration(
    Request<_trt__GetAudioSourceConfiguration>& request) const
{
    _trt__GetAudioSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSourceConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioEncoderConfigurationResponse> OnvifMediaClient::GetAudioEncoderConfiguration(
    Request<_trt__GetAudioEncoderConfiguration>& request) const
{
    _trt__GetAudioEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioEncoderConfiguration(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoAnalyticsConfigurationResponse> OnvifMediaClient::GetVideoAnalyticsConfiguration(
    Request<_trt__GetVideoAnalyticsConfiguration>& request) const
{
    _trt__GetVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoAnalyticsConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetMetadataConfigurationResponse> OnvifMediaClient::GetMetadataConfiguration(
    Request<_trt__GetMetadataConfiguration>& request) const
{
    _trt__GetMetadataConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMetadataConfiguration(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetMetadataConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioOutputConfigurationResponse> OnvifMediaClient::GetAudioOutputConfiguration(
    Request<_trt__GetAudioOutputConfiguration>& request) const
{
    _trt__GetAudioOutputConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputConfiguration(GetEndpoint().c_str(),
                                                      !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioOutputConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioDecoderConfigurationResponse> OnvifMediaClient::GetAudioDecoderConfiguration(
    Request<_trt__GetAudioDecoderConfiguration>& request) const
{
    _trt__GetAudioDecoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioDecoderConfiguration(GetEndpoint().c_str(),
                                                     !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioDecoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleVideoEncoderConfigurationsResponse> OnvifMediaClient::
GetCompatibleVideoEncoderConfigurations(Request<_trt__GetCompatibleVideoEncoderConfigurations>& request) const
{
    _trt__GetCompatibleVideoEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleVideoEncoderConfigurations(GetEndpoint().c_str(),
                                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleVideoEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleVideoSourceConfigurationsResponse> OnvifMediaClient::GetCompatibleVideoSourceConfigurations(
    Request<_trt__GetCompatibleVideoSourceConfigurations>& request) const
{
    _trt__GetCompatibleVideoSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleVideoSourceConfigurations(GetEndpoint().c_str(),
                                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleVideoSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleAudioEncoderConfigurationsResponse> OnvifMediaClient::
GetCompatibleAudioEncoderConfigurations(Request<_trt__GetCompatibleAudioEncoderConfigurations>& request) const
{
    _trt__GetCompatibleAudioEncoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleAudioEncoderConfigurations(GetEndpoint().c_str(),
                                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleAudioEncoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleAudioSourceConfigurationsResponse> OnvifMediaClient::GetCompatibleAudioSourceConfigurations(
    Request<_trt__GetCompatibleAudioSourceConfigurations>& request) const
{
    _trt__GetCompatibleAudioSourceConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleAudioSourceConfigurations(GetEndpoint().c_str(),
                                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleAudioSourceConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleVideoAnalyticsConfigurationsResponse> OnvifMediaClient::
GetCompatibleVideoAnalyticsConfigurations(Request<_trt__GetCompatibleVideoAnalyticsConfigurations>& request) const
{
    _trt__GetCompatibleVideoAnalyticsConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleVideoAnalyticsConfigurations(GetEndpoint().c_str(),
                                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleVideoAnalyticsConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleMetadataConfigurationsResponse> OnvifMediaClient::GetCompatibleMetadataConfigurations(
    Request<_trt__GetCompatibleMetadataConfigurations>& request) const
{
    _trt__GetCompatibleMetadataConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleMetadataConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleMetadataConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleAudioOutputConfigurationsResponse> OnvifMediaClient::GetCompatibleAudioOutputConfigurations(
    Request<_trt__GetCompatibleAudioOutputConfigurations>& request) const
{
    _trt__GetCompatibleAudioOutputConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleAudioOutputConfigurations(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleAudioOutputConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetCompatibleAudioDecoderConfigurationsResponse> OnvifMediaClient::
GetCompatibleAudioDecoderConfigurations(Request<_trt__GetCompatibleAudioDecoderConfigurations>& request) const
{
    _trt__GetCompatibleAudioDecoderConfigurationsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetCompatibleAudioDecoderConfigurations(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                        &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetCompatibleAudioDecoderConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetVideoSourceConfigurationResponse> OnvifMediaClient::SetVideoSourceConfiguration(
    Request<_trt__SetVideoSourceConfiguration>& request) const
{
    _trt__SetVideoSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoSourceConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetVideoSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetVideoEncoderConfigurationResponse> OnvifMediaClient::SetVideoEncoderConfiguration(
    Request<_trt__SetVideoEncoderConfiguration>& request) const
{
    _trt__SetVideoEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoEncoderConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetVideoEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetAudioSourceConfigurationResponse> OnvifMediaClient::SetAudioSourceConfiguration(
    Request<_trt__SetAudioSourceConfiguration>& request) const
{
    _trt__SetAudioSourceConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioSourceConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetAudioSourceConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetAudioEncoderConfigurationResponse> OnvifMediaClient::SetAudioEncoderConfiguration(
    Request<_trt__SetAudioEncoderConfiguration>& request) const
{
    _trt__SetAudioEncoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioEncoderConfiguration(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetAudioEncoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetVideoAnalyticsConfigurationResponse> OnvifMediaClient::SetVideoAnalyticsConfiguration(
    Request<_trt__SetVideoAnalyticsConfiguration>& request) const
{
    _trt__SetVideoAnalyticsConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoAnalyticsConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    } while (ReTry(soap_ctx));
    auto response = Response<_trt__SetVideoAnalyticsConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetMetadataConfigurationResponse> OnvifMediaClient::SetMetadataConfiguration(
    Request<_trt__SetMetadataConfiguration>& request) const
{
    _trt__SetMetadataConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetMetadataConfiguration(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetMetadataConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetAudioOutputConfigurationResponse> OnvifMediaClient::SetAudioOutputConfiguration(
    Request<_trt__SetAudioOutputConfiguration>& request) const
{
    _trt__SetAudioOutputConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioOutputConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetAudioOutputConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetAudioDecoderConfigurationResponse> OnvifMediaClient::SetAudioDecoderConfiguration(
    Request<_trt__SetAudioDecoderConfiguration>& request) const
{
    _trt__SetAudioDecoderConfigurationResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetAudioDecoderConfiguration(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetAudioDecoderConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoSourceConfigurationOptionsResponse> OnvifMediaClient::GetVideoSourceConfigurationOptions(
    Request<_trt__GetVideoSourceConfigurationOptions>& request) const
{
    _trt__GetVideoSourceConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceConfigurationOptions(GetEndpoint().c_str(),
                                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoSourceConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoEncoderConfigurationOptionsResponse> OnvifMediaClient::GetVideoEncoderConfigurationOptions(
    Request<_trt__GetVideoEncoderConfigurationOptions>& request) const
{
    _trt__GetVideoEncoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoEncoderConfigurationOptions(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoEncoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioSourceConfigurationOptionsResponse> OnvifMediaClient::GetAudioSourceConfigurationOptions(
    Request<_trt__GetAudioSourceConfigurationOptions>& request) const
{
    _trt__GetAudioSourceConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioSourceConfigurationOptions(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioSourceConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioEncoderConfigurationOptionsResponse> OnvifMediaClient::GetAudioEncoderConfigurationOptions(
    Request<_trt__GetAudioEncoderConfigurationOptions>& request) const
{
    _trt__GetAudioEncoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioEncoderConfigurationOptions(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioEncoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetMetadataConfigurationOptionsResponse> OnvifMediaClient::GetMetadataConfigurationOptions(
    Request<_trt__GetMetadataConfigurationOptions>& request) const
{
    _trt__GetMetadataConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetMetadataConfigurationOptions(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetMetadataConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioOutputConfigurationOptionsResponse> OnvifMediaClient::GetAudioOutputConfigurationOptions(
    Request<_trt__GetAudioOutputConfigurationOptions>& request) const
{
    _trt__GetAudioOutputConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioOutputConfigurationOptions(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioOutputConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetAudioDecoderConfigurationOptionsResponse> OnvifMediaClient::GetAudioDecoderConfigurationOptions(
    Request<_trt__GetAudioDecoderConfigurationOptions>& request) const
{
    _trt__GetAudioDecoderConfigurationOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetAudioDecoderConfigurationOptions(GetEndpoint().c_str(),
                                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetAudioDecoderConfigurationOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse>
OnvifMediaClient::GetGuaranteedNumberOfVideoEncoderInstances(Request<_trt__GetGuaranteedNumberOfVideoEncoderInstances>& request) const
{
    _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetGuaranteedNumberOfVideoEncoderInstances(GetEndpoint().c_str(),
                                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetStreamUriResponse> OnvifMediaClient::GetStreamUri(Request<_trt__GetStreamUri>& request) const
{
    _trt__GetStreamUriResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetStreamUri(GetEndpoint().c_str(),
                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetStreamUriResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__StartMulticastStreamingResponse> OnvifMediaClient::StartMulticastStreaming(
    Request<_trt__StartMulticastStreaming>& request) const
{
    _trt__StartMulticastStreamingResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.StartMulticastStreaming(GetEndpoint().c_str(),
                                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__StartMulticastStreamingResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__StopMulticastStreamingResponse> OnvifMediaClient::StopMulticastStreaming(
    Request<_trt__StopMulticastStreaming>& request) const
{
    _trt__StopMulticastStreamingResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.StopMulticastStreaming(GetEndpoint().c_str(),
                                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__StopMulticastStreamingResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetSynchronizationPointResponse> OnvifMediaClient::SetSynchronizationPoint(
    Request<_trt__SetSynchronizationPoint>& request) const
{
    _trt__SetSynchronizationPointResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetSynchronizationPoint(GetEndpoint().c_str(),
                                                      !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetSynchronizationPointResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetSnapshotUriResponse> OnvifMediaClient::GetSnapshotUri(Request<_trt__GetSnapshotUri>& request) const
{
    _trt__GetSnapshotUriResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetSnapshotUri(GetEndpoint().c_str(),
                                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetSnapshotUriResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetVideoSourceModesResponse>
OnvifMediaClient::GetVideoSourceModes(Request<_trt__GetVideoSourceModes>& request) const
{
    _trt__GetVideoSourceModesResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetVideoSourceModes(GetEndpoint().c_str(),
                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetVideoSourceModesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetVideoSourceModeResponse> OnvifMediaClient::SetVideoSourceMode(
    Request<_trt__SetVideoSourceMode>& request) const
{
    _trt__SetVideoSourceModeResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetVideoSourceMode(GetEndpoint().c_str(),
                                                !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetVideoSourceModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetOSDsResponse> OnvifMediaClient::GetOSDs(Request<_trt__GetOSDs>& request) const
{
    _trt__GetOSDsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetOSDs(GetEndpoint().c_str(),
                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetOSDsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetOSDResponse> OnvifMediaClient::GetOSD(Request<_trt__GetOSD>& request) const
{
    _trt__GetOSDResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetOSD(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetOSDResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__GetOSDOptionsResponse> OnvifMediaClient::GetOSDOptions(Request<_trt__GetOSDOptions>& request) const
{
    _trt__GetOSDOptionsResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.GetOSDOptions(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__GetOSDOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__SetOSDResponse> OnvifMediaClient::SetOSD(Request<_trt__SetOSD>& request) const
{
    _trt__SetOSDResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.SetOSD(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__SetOSDResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__CreateOSDResponse> OnvifMediaClient::CreateOSD(Request<_trt__CreateOSD>& request) const
{
    _trt__CreateOSDResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.CreateOSD(GetEndpoint().c_str(),
                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__CreateOSDResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}

Response<_trt__DeleteOSDResponse> OnvifMediaClient::DeleteOSD(Request<_trt__DeleteOSD>& request) const
{
    _trt__DeleteOSDResponse response_object;
    const auto soap_ctx = AcquireContext();
    do
    {
        impl_->media_binding_proxy.DeleteOSD(GetEndpoint().c_str(),
                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                                &request, response_object);
    }while (ReTry(soap_ctx));
    auto response = Response<_trt__DeleteOSDResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ctx);
    return response.Build();
}
