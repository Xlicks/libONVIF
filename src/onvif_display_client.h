//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_DISPLAY_CLIENT_H
#define ONVIF_DISPLAY_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifDisplayClientImplementation;

class OnvifDisplayClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifDisplayClient);
    explicit OnvifDisplayClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifDisplayClient() override;

    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver10/display/wsdl"; }
    Response<_tls__GetServiceCapabilitiesResponse>GetServiceCapabilities(Request<_tls__GetServiceCapabilities> &request) const;
    Response<_tls__GetLayoutResponse>GetLayout(Request<_tls__GetLayout> &request) const;
    Response<_tls__SetLayoutResponse>SetLayout(Request<_tls__SetLayout> &request) const;
    Response<_tls__GetDisplayOptionsResponse>GetDisplayOptions(Request<_tls__GetDisplayOptions> &request) const;
    Response<_tls__GetPaneConfigurationsResponse>GetPaneConfigurations(Request<_tls__GetPaneConfigurations> &request) const;
    Response<_tls__GetPaneConfigurationResponse>GetPaneConfiguration(Request<_tls__GetPaneConfiguration> &request) const;
    Response<_tls__SetPaneConfigurationsResponse>SetPaneConfigurations(Request<_tls__SetPaneConfigurations> &request) const;
    Response<_tls__SetPaneConfigurationResponse>SetPaneConfiguration(Request<_tls__SetPaneConfiguration> &request) const;
    Response<_tls__CreatePaneConfigurationResponse>CreatePaneConfiguration(Request<_tls__CreatePaneConfiguration> &request) const;
    Response<_tls__DeletePaneConfigurationResponse>DeletePaneConfiguration(Request<_tls__DeletePaneConfiguration> &request) const;
private:
    OnvifDisplayClientImplementation* impl_;
};

#endif //ONVIF_DISPLAY_CLIENT_H
