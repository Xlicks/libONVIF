//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_ANALYTICS_CLIENT_H
#define ONVIF_ANALYTICS_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifAnalyticsClientImplementation;

class OnvifAnalyticsClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifAnalyticsClient);
    explicit OnvifAnalyticsClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifAnalyticsClient() override;

    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver20/analytics/wsdl"; }
    // 添加 const 修饰符
    Response<_tad__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_tad__GetServiceCapabilities> &request) const;
    Response<_tad__DeleteAnalyticsEngineControlResponse> DeleteAnalyticsEngineControl(Request<_tad__DeleteAnalyticsEngineControl> &request) const;
    Response<_tad__CreateAnalyticsEngineControlResponse> CreateAnalyticsEngineControl(Request<_tad__CreateAnalyticsEngineControl> &request) const;
    Response<_tad__SetAnalyticsEngineControlResponse> SetAnalyticsEngineControl(Request<_tad__SetAnalyticsEngineControl> &request) const;
    Response<_tad__GetAnalyticsEngineControlResponse> GetAnalyticsEngineControl(Request<_tad__GetAnalyticsEngineControl> &request) const;
    Response<_tad__GetAnalyticsEngineControlsResponse> GetAnalyticsEngineControls(Request<_tad__GetAnalyticsEngineControls> &request) const;
    Response<_tad__GetAnalyticsEngineResponse> GetAnalyticsEngine(Request<_tad__GetAnalyticsEngine> &request) const;
    Response<_tad__GetAnalyticsEnginesResponse> GetAnalyticsEngines(Request<_tad__GetAnalyticsEngines> &request) const;
    Response<_tad__SetVideoAnalyticsConfigurationResponse> SetVideoAnalyticsConfiguration(Request<_tad__SetVideoAnalyticsConfiguration> &request) const;
    Response<_tad__GetAnalyticsEngineInputResponse> GetAnalyticsEngineInput(Request<_tad__GetAnalyticsEngineInput> &request) const;
    Response<_tad__GetAnalyticsEngineInputsResponse> GetAnalyticsEngineInputs(Request<_tad__GetAnalyticsEngineInputs> &request) const;
    Response<_tad__GetAnalyticsDeviceStreamUriResponse> GetAnalyticsDeviceStreamUri(Request<_tad__GetAnalyticsDeviceStreamUri> &request) const;
    Response<_tad__GetVideoAnalyticsConfigurationResponse> GetVideoAnalyticsConfiguration(Request<_tad__GetVideoAnalyticsConfiguration> &request) const;
    Response<_tad__CreateAnalyticsEngineInputsResponse> CreateAnalyticsEngineInputs(Request<_tad__CreateAnalyticsEngineInputs> &request) const;
    Response<_tad__DeleteAnalyticsEngineInputsResponse> DeleteAnalyticsEngineInputs(Request<_tad__DeleteAnalyticsEngineInputs> &request) const;
    Response<_tad__GetAnalyticsStateResponse> GetAnalyticsState(Request<_tad__GetAnalyticsState> &request) const;
private:
    OnvifAnalyticsClientImplementation *impl_;
};


#endif //ONVIF_ANALYTICS_CLIENT_H
