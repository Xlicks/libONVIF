//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_MEDIA2_CLIENT_H
#define ONVIF_MEDIA2_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifMedia2ClientImplementation;

class OnvifMedia2Client final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifMedia2Client);
    explicit OnvifMedia2Client(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifMedia2Client() override;
    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver20/media/wsdl"; }
    Response<_ns1__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_ns1__GetServiceCapabilities> &request) const;
    Response<_ns1__CreateProfileResponse> CreateProfile(Request<_ns1__CreateProfile> &request) const;
    Response<_ns1__GetProfilesResponse> GetProfiles(Request<_ns1__GetProfiles> &request) const;
    Response<_ns1__AddConfigurationResponse> AddConfiguration(Request<_ns1__AddConfiguration> &request) const;
    Response<_ns1__RemoveConfigurationResponse> RemoveConfiguration(Request<_ns1__RemoveConfiguration> &request) const;
    Response<_ns1__DeleteProfileResponse> DeleteProfile(Request<_ns1__DeleteProfile> &request) const;
    Response<_ns1__GetVideoSourceConfigurationsResponse> GetVideoSourceConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetVideoEncoderConfigurationsResponse> GetVideoEncoderConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioSourceConfigurationsResponse> GetAudioSourceConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioEncoderConfigurationsResponse> GetAudioEncoderConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAnalyticsConfigurationsResponse> GetAnalyticsConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetMetadataConfigurationsResponse> GetMetadataConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioOutputConfigurationsResponse> GetAudioOutputConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioDecoderConfigurationsResponse> GetAudioDecoderConfigurations(Request<ns1__GetConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetVideoSourceConfiguration(Request<_ns1__SetVideoSourceConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetVideoEncoderConfiguration(Request<_ns1__SetVideoEncoderConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetAudioSourceConfiguration(Request<_ns1__SetAudioSourceConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetAudioEncoderConfiguration(Request<_ns1__SetAudioEncoderConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetMetadataConfiguration(Request<_ns1__SetMetadataConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetAudioOutputConfiguration(Request<_ns1__SetAudioOutputConfiguration> &request) const;
    Response<ns1__SetConfigurationResponse> SetAudioDecoderConfiguration(Request<_ns1__SetAudioDecoderConfiguration> &request) const;
    Response<_ns1__GetVideoSourceConfigurationOptionsResponse> GetVideoSourceConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetVideoEncoderConfigurationOptionsResponse> GetVideoEncoderConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioSourceConfigurationOptionsResponse> GetAudioSourceConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioEncoderConfigurationOptionsResponse> GetAudioEncoderConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetMetadataConfigurationOptionsResponse> GetMetadataConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioOutputConfigurationOptionsResponse> GetAudioOutputConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetAudioDecoderConfigurationOptionsResponse> GetAudioDecoderConfigurationOptions(Request<ns1__GetConfiguration> &request) const;
    Response<_ns1__GetVideoEncoderInstancesResponse> GetVideoEncoderInstances(Request<_ns1__GetVideoEncoderInstances> &request) const;
    Response<_ns1__GetStreamUriResponse> GetStreamUri(Request<_ns1__GetStreamUri> &request) const;
    Response<ns1__SetConfigurationResponse> StartMulticastStreaming(Request<ns1__StartStopMulticastStreaming> &request) const;
    Response<ns1__SetConfigurationResponse> StopMulticastStreaming(Request<ns1__StartStopMulticastStreaming> &request) const;
    Response<_ns1__SetSynchronizationPointResponse> SetSynchronizationPoint(Request<_ns1__SetSynchronizationPoint> &request) const;
    Response<_ns1__GetSnapshotUriResponse> GetSnapshotUri(Request<_ns1__GetSnapshotUri> &request) const;
    Response<_ns1__GetVideoSourceModesResponse> GetVideoSourceModes(Request<_ns1__GetVideoSourceModes> &request) const;
    Response<_ns1__SetVideoSourceModeResponse> SetVideoSourceMode(Request<_ns1__SetVideoSourceMode> &request) const;
    Response<_ns1__GetOSDsResponse> GetOSDs(Request<_ns1__GetOSDs> &request) const;
    Response<_ns1__GetOSDOptionsResponse> GetOSDOptions(Request<_ns1__GetOSDOptions> &request) const;
    Response<ns1__SetConfigurationResponse> SetOSD(Request<_ns1__SetOSD> &request) const;
    Response<_ns1__CreateOSDResponse> CreateOSD(Request<_ns1__CreateOSD> &request) const;
    Response<ns1__SetConfigurationResponse> DeleteOSD(Request<_ns1__DeleteOSD> &request) const;
    Response<_ns1__GetMasksResponse> GetMasks(Request<_ns1__GetMasks> &request) const;
    Response<_ns1__GetMaskOptionsResponse> GetMaskOptions(Request<_ns1__GetMaskOptions> &request) const;
    Response<ns1__SetConfigurationResponse> SetMask(Request<_ns1__SetMask> &request) const;
    Response<_ns1__CreateMaskResponse> CreateMask(Request<_ns1__CreateMask> &request) const;
    Response<ns1__SetConfigurationResponse> DeleteMask(Request<_ns1__DeleteMask> &request) const;
private:
    OnvifMedia2ClientImplementation* impl_;
};

#endif //ONVIF_MEDIA2_CLIENT_H
