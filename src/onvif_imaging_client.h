//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_IMAGING_CLIENT_H
#define ONVIF_IMAGING_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifImagingClientImplementation;
class OnvifImagingClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifImagingClient);
    explicit OnvifImagingClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifImagingClient() override;
    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver20/imaging/wsdl"; }
    Response<_timg__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_timg__GetServiceCapabilities>& request) const;
    Response<_timg__GetImagingSettingsResponse> GetImagingSettings(Request<_timg__GetImagingSettings> &request) const;
    Response<_timg__SetImagingSettingsResponse> SetImagingSettings(Request<_timg__SetImagingSettings> &request) const;
    Response<_timg__GetOptionsResponse> GetOptions(Request<_timg__GetOptions> &rRequest) const;
    Response<_timg__MoveResponse> Move(Request<_timg__Move> &request) const;
    Response<_timg__StopResponse> Stop(Request<_timg__Stop> &request) const;
    Response<_timg__GetStatusResponse> GetStatus(Request<_timg__GetStatus> &request) const;
    Response<_timg__GetMoveOptionsResponse> GetMoveOptions(Request<_timg__GetMoveOptions> &request) const;
    Response<_timg__GetPresetsResponse> GetPresets(Request<_timg__GetPresets> &request) const;
    Response<_timg__GetCurrentPresetResponse> GetCurrentPreset(Request<_timg__GetCurrentPreset> &request) const;
    Response<_timg__SetCurrentPresetResponse> SetCurrentPreset(Request<_timg__SetCurrentPreset> &request) const;
private:
    OnvifImagingClientImplementation* impl_;
};

#endif //ONVIF_IMAGING_CLIENT_H
