//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_MEDIA_CLIENT_H
#define ONVIF_MEDIA_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifMediaClientImplementation;

class OnvifMediaClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifMediaClient);
    explicit OnvifMediaClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifMediaClient() override;

    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver10/media/wsdl"; }
    Response<_trt__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_trt__GetServiceCapabilities> &request) const;
    Response<_trt__GetVideoSourcesResponse> GetVideoSources(Request<_trt__GetVideoSources> &request) const;
    Response<_trt__GetAudioSourcesResponse> GetAudioSources(Request<_trt__GetAudioSources> &request) const;
    Response<_trt__GetAudioOutputsResponse> GetAudioOutputs(Request<_trt__GetAudioOutputs> &request) const;
    Response<_trt__CreateProfileResponse> CreateProfile(Request<_trt__CreateProfile> &request) const;
    Response<_trt__GetProfileResponse> GetProfile(Request<_trt__GetProfile> &request) const;
    Response<_trt__GetProfilesResponse> GetProfiles(Request<_trt__GetProfiles> &request) const;
    Response<_trt__AddVideoEncoderConfigurationResponse> AddVideoEncoderConfiguration(Request<_trt__AddVideoEncoderConfiguration> &request) const;
    Response<_trt__AddVideoSourceConfigurationResponse> AddVideoSourceConfiguration(Request<_trt__AddVideoSourceConfiguration> &request) const;
    Response<_trt__AddAudioEncoderConfigurationResponse> AddAudioEncoderConfiguration(Request<_trt__AddAudioEncoderConfiguration> &request) const;
    Response<_trt__AddAudioSourceConfigurationResponse> AddAudioSourceConfiguration(Request<_trt__AddAudioSourceConfiguration> &request) const;
    Response<_trt__AddPTZConfigurationResponse> AddPTZConfiguration(Request<_trt__AddPTZConfiguration> &request) const;
    Response<_trt__AddVideoAnalyticsConfigurationResponse> AddVideoAnalyticsConfiguration(Request<_trt__AddVideoAnalyticsConfiguration> &request) const;
    Response<_trt__AddMetadataConfigurationResponse> AddMetadataConfiguration(Request<_trt__AddMetadataConfiguration> &request) const;
    Response<_trt__AddAudioOutputConfigurationResponse> AddAudioOutputConfiguration(Request<_trt__AddAudioOutputConfiguration> &request) const;
    Response<_trt__AddAudioDecoderConfigurationResponse> AddAudioDecoderConfiguration(Request<_trt__AddAudioDecoderConfiguration> &request) const;
    Response<_trt__RemoveVideoEncoderConfigurationResponse> RemoveVideoEncoderConfiguration(Request<_trt__RemoveVideoEncoderConfiguration> &request) const;
    Response<_trt__RemoveVideoSourceConfigurationResponse> RemoveVideoSourceConfiguration(Request<_trt__RemoveVideoSourceConfiguration> &request) const;
    Response<_trt__RemoveAudioEncoderConfigurationResponse> RemoveAudioEncoderConfiguration(Request<_trt__RemoveAudioEncoderConfiguration> &request) const;
    Response<_trt__RemoveAudioSourceConfigurationResponse> RemoveAudioSourceConfiguration(Request<_trt__RemoveAudioSourceConfiguration> &request) const;
    Response<_trt__RemovePTZConfigurationResponse> RemovePTZConfiguration(Request<_trt__RemovePTZConfiguration> &request) const;
    Response<_trt__RemoveVideoAnalyticsConfigurationResponse> RemoveVideoAnalyticsConfiguration(Request<_trt__RemoveVideoAnalyticsConfiguration> &request) const;
    Response<_trt__RemoveMetadataConfigurationResponse> RemoveMetadataConfiguration(Request<_trt__RemoveMetadataConfiguration> &request) const;
    Response<_trt__RemoveAudioOutputConfigurationResponse> RemoveAudioOutputConfiguration(Request<_trt__RemoveAudioOutputConfiguration> &request) const;
    Response<_trt__RemoveAudioDecoderConfigurationResponse> RemoveAudioDecoderConfiguration(Request<_trt__RemoveAudioDecoderConfiguration> &request) const;
    Response<_trt__DeleteProfileResponse> DeleteProfile(Request<_trt__DeleteProfile> &request) const;
    Response<_trt__GetVideoSourceConfigurationsResponse> GetVideoSourceConfigurations(Request<_trt__GetVideoSourceConfigurations> &request) const;
    Response<_trt__GetVideoEncoderConfigurationsResponse> GetVideoEncoderConfigurations(Request<_trt__GetVideoEncoderConfigurations> &request) const;
    Response<_trt__GetAudioSourceConfigurationsResponse> GetAudioSourceConfigurations(Request<_trt__GetAudioSourceConfigurations> &request) const;
    Response<_trt__GetAudioEncoderConfigurationsResponse> GetAudioEncoderConfigurations(Request<_trt__GetAudioEncoderConfigurations> &request) const;
    Response<_trt__GetVideoAnalyticsConfigurationsResponse> GetVideoAnalyticsConfigurations(Request<_trt__GetVideoAnalyticsConfigurations> &request) const;
    Response<_trt__GetMetadataConfigurationsResponse> GetMetadataConfigurations(Request<_trt__GetMetadataConfigurations> &request) const;
    Response<_trt__GetAudioOutputConfigurationsResponse> GetAudioOutputConfigurations(Request<_trt__GetAudioOutputConfigurations> &request) const;
    Response<_trt__GetAudioDecoderConfigurationsResponse> GetAudioDecoderConfigurations(Request<_trt__GetAudioDecoderConfigurations> &request) const;
    Response<_trt__GetVideoSourceConfigurationResponse> GetVideoSourceConfiguration(Request<_trt__GetVideoSourceConfiguration> &request) const;
    Response<_trt__GetVideoEncoderConfigurationResponse> GetVideoEncoderConfiguration(Request<_trt__GetVideoEncoderConfiguration> &request) const;
    Response<_trt__GetAudioSourceConfigurationResponse> GetAudioSourceConfiguration(Request<_trt__GetAudioSourceConfiguration> &request) const;
    Response<_trt__GetAudioEncoderConfigurationResponse> GetAudioEncoderConfiguration(Request<_trt__GetAudioEncoderConfiguration> &request) const;
    Response<_trt__GetVideoAnalyticsConfigurationResponse> GetVideoAnalyticsConfiguration(Request<_trt__GetVideoAnalyticsConfiguration> &request) const;
    Response<_trt__GetMetadataConfigurationResponse> GetMetadataConfiguration(Request<_trt__GetMetadataConfiguration> &request) const;
    Response<_trt__GetAudioOutputConfigurationResponse> GetAudioOutputConfiguration(Request<_trt__GetAudioOutputConfiguration> &request) const;
    Response<_trt__GetAudioDecoderConfigurationResponse> GetAudioDecoderConfiguration(Request<_trt__GetAudioDecoderConfiguration> &request) const;
    Response<_trt__GetCompatibleVideoEncoderConfigurationsResponse> GetCompatibleVideoEncoderConfigurations(Request<_trt__GetCompatibleVideoEncoderConfigurations> &request) const;
    Response<_trt__GetCompatibleVideoSourceConfigurationsResponse> GetCompatibleVideoSourceConfigurations(Request<_trt__GetCompatibleVideoSourceConfigurations> &request) const;
    Response<_trt__GetCompatibleAudioEncoderConfigurationsResponse> GetCompatibleAudioEncoderConfigurations(Request<_trt__GetCompatibleAudioEncoderConfigurations> &request) const;
    Response<_trt__GetCompatibleAudioSourceConfigurationsResponse> GetCompatibleAudioSourceConfigurations(Request<_trt__GetCompatibleAudioSourceConfigurations> &request) const;
    Response<_trt__GetCompatibleVideoAnalyticsConfigurationsResponse> GetCompatibleVideoAnalyticsConfigurations(Request<_trt__GetCompatibleVideoAnalyticsConfigurations> &request) const;
    Response<_trt__GetCompatibleMetadataConfigurationsResponse> GetCompatibleMetadataConfigurations(Request<_trt__GetCompatibleMetadataConfigurations> &request) const;
    Response<_trt__GetCompatibleAudioOutputConfigurationsResponse> GetCompatibleAudioOutputConfigurations(Request<_trt__GetCompatibleAudioOutputConfigurations> &request) const;
    Response<_trt__GetCompatibleAudioDecoderConfigurationsResponse> GetCompatibleAudioDecoderConfigurations(Request<_trt__GetCompatibleAudioDecoderConfigurations> &request) const;
    Response<_trt__SetVideoSourceConfigurationResponse> SetVideoSourceConfiguration(Request<_trt__SetVideoSourceConfiguration> &request) const;
    Response<_trt__SetVideoEncoderConfigurationResponse> SetVideoEncoderConfiguration(Request<_trt__SetVideoEncoderConfiguration> &request) const;
    Response<_trt__SetAudioSourceConfigurationResponse> SetAudioSourceConfiguration(Request<_trt__SetAudioSourceConfiguration> &request) const;
    Response<_trt__SetAudioEncoderConfigurationResponse> SetAudioEncoderConfiguration(Request<_trt__SetAudioEncoderConfiguration> &request) const;
    Response<_trt__SetVideoAnalyticsConfigurationResponse> SetVideoAnalyticsConfiguration(Request<_trt__SetVideoAnalyticsConfiguration> &request) const;
    Response<_trt__SetMetadataConfigurationResponse> SetMetadataConfiguration(Request<_trt__SetMetadataConfiguration> &request) const;
    Response<_trt__SetAudioOutputConfigurationResponse> SetAudioOutputConfiguration(Request<_trt__SetAudioOutputConfiguration> &request) const;
    Response<_trt__SetAudioDecoderConfigurationResponse> SetAudioDecoderConfiguration(Request<_trt__SetAudioDecoderConfiguration> &request) const;
    Response<_trt__GetVideoSourceConfigurationOptionsResponse> GetVideoSourceConfigurationOptions(Request<_trt__GetVideoSourceConfigurationOptions> &request) const;
    Response<_trt__GetVideoEncoderConfigurationOptionsResponse> GetVideoEncoderConfigurationOptions(Request<_trt__GetVideoEncoderConfigurationOptions> &request) const;
    Response<_trt__GetAudioSourceConfigurationOptionsResponse> GetAudioSourceConfigurationOptions(Request<_trt__GetAudioSourceConfigurationOptions> &request) const;
    Response<_trt__GetAudioEncoderConfigurationOptionsResponse> GetAudioEncoderConfigurationOptions(Request<_trt__GetAudioEncoderConfigurationOptions> &request) const;
    Response<_trt__GetMetadataConfigurationOptionsResponse> GetMetadataConfigurationOptions(Request<_trt__GetMetadataConfigurationOptions> &request) const;
    Response<_trt__GetAudioOutputConfigurationOptionsResponse> GetAudioOutputConfigurationOptions(Request<_trt__GetAudioOutputConfigurationOptions> &request) const;
    Response<_trt__GetAudioDecoderConfigurationOptionsResponse> GetAudioDecoderConfigurationOptions(Request<_trt__GetAudioDecoderConfigurationOptions> &request) const;
    Response<_trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse> GetGuaranteedNumberOfVideoEncoderInstances(Request<_trt__GetGuaranteedNumberOfVideoEncoderInstances> &request) const;
    Response<_trt__GetStreamUriResponse> GetStreamUri(Request<_trt__GetStreamUri> &request) const;
    Response<_trt__StartMulticastStreamingResponse> StartMulticastStreaming(Request<_trt__StartMulticastStreaming> &request) const;
    Response<_trt__StopMulticastStreamingResponse> StopMulticastStreaming(Request<_trt__StopMulticastStreaming> &request) const;
    Response<_trt__SetSynchronizationPointResponse> SetSynchronizationPoint(Request<_trt__SetSynchronizationPoint> &request) const;
    Response<_trt__GetSnapshotUriResponse> GetSnapshotUri(Request<_trt__GetSnapshotUri> &request) const;
    Response<_trt__GetVideoSourceModesResponse> GetVideoSourceModes(Request<_trt__GetVideoSourceModes> &request) const;
    Response<_trt__SetVideoSourceModeResponse> SetVideoSourceMode(Request<_trt__SetVideoSourceMode> &request) const;
    Response<_trt__GetOSDsResponse> GetOSDs(Request<_trt__GetOSDs> &request) const;
    Response<_trt__GetOSDResponse> GetOSD(Request<_trt__GetOSD> &request) const;
    Response<_trt__GetOSDOptionsResponse> GetOSDOptions(Request<_trt__GetOSDOptions> &request) const;
    Response<_trt__SetOSDResponse> SetOSD(Request<_trt__SetOSD> &request) const;
    Response<_trt__CreateOSDResponse> CreateOSD(Request<_trt__CreateOSD> &request) const;
    Response<_trt__DeleteOSDResponse> DeleteOSD(Request<_trt__DeleteOSD> &request) const;

private:
    OnvifMediaClientImplementation* impl_;
};

#endif //ONVIF_MEDIA_CLIENT_H
