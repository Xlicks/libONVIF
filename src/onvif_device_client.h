//
// Created by licks on 24-7-2.
//

#ifndef ONVIF_DEVICE_CLIENT_H
#define ONVIF_DEVICE_CLIENT_H
#include "onvif_client.h"
#include "response.h"
#include "request.h"

struct OnvifDeviceClientImplementation;

class OnvifDeviceClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifDeviceClient);
    explicit OnvifDeviceClient(const std::string& endpoint, std::shared_ptr<SoapContext> soap_ctx = std::make_shared<SoapContext>());
    ~OnvifDeviceClient() override;
    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver10/device/wsdl"; }
    Response<_tds__GetServicesResponse> GetServices(Request<_tds__GetServices> &request) const;
    Response<_tds__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_tds__GetServiceCapabilities> &request) const;
    Response<_tds__GetDeviceInformationResponse> GetDeviceInformation(Request<_tds__GetDeviceInformation> &request) const;
    Response<_tds__SetSystemDateAndTimeResponse> SetSystemDateAndTime(Request<_tds__SetSystemDateAndTime> &request) const;
    Response<_tds__GetSystemDateAndTimeResponse> GetSystemDateAndTime(Request<_tds__GetSystemDateAndTime> &request) const;
    Response<_tds__SetSystemFactoryDefaultResponse> SetSystemFactoryDefault(Request<_tds__SetSystemFactoryDefault> &request) const;
    Response<_tds__UpgradeSystemFirmwareResponse> UpgradeSystemFirmware(Request<_tds__UpgradeSystemFirmware> &request) const;
    Response<_tds__SystemRebootResponse> SystemReboot(Request<_tds__SystemReboot> &request) const;
    Response<_tds__RestoreSystemResponse> RestoreSystem(Request<_tds__RestoreSystem> &request) const;
    Response<_tds__GetSystemBackupResponse> GetSystemBackup(Request<_tds__GetSystemBackup> &request) const;
    Response<_tds__GetSystemLogResponse> GetSystemLog(Request<_tds__GetSystemLog> &request) const;
    Response<_tds__GetSystemSupportInformationResponse> GetSystemSupportInformation(Request<_tds__GetSystemSupportInformation> &request) const;
    Response<_tds__GetScopesResponse> GetScopes(Request<_tds__GetScopes> &request) const;
    Response<_tds__SetScopesResponse> SetScopes(Request<_tds__SetScopes> &request) const;
    Response<_tds__AddScopesResponse> AddScopes(Request<_tds__AddScopes> &request) const;
    Response<_tds__RemoveScopesResponse> RemoveScopes(Request<_tds__RemoveScopes> &request) const;
    Response<_tds__GetDiscoveryModeResponse> GetDiscoveryMode(Request<_tds__GetDiscoveryMode> &request) const;
    Response<_tds__SetDiscoveryModeResponse> SetDiscoveryMode(Request<_tds__SetDiscoveryMode> &request) const;
    Response<_tds__GetRemoteDiscoveryModeResponse> GetRemoteDiscoveryMode(Request<_tds__GetRemoteDiscoveryMode> &request) const;
    Response<_tds__SetRemoteDiscoveryModeResponse> SetRemoteDiscoveryMode(Request<_tds__SetRemoteDiscoveryMode> &request) const;
    Response<_tds__GetDPAddressesResponse> GetDPAddresses(Request<_tds__GetDPAddresses> &request) const;
    Response<_tds__GetEndpointReferenceResponse> GetEndpointReference(Request<_tds__GetEndpointReference> &request) const;
    Response<_tds__GetRemoteUserResponse> GetRemoteUser(Request<_tds__GetRemoteUser> &request) const;
    Response<_tds__SetRemoteUserResponse> SetRemoteUser(Request<_tds__SetRemoteUser> &request) const;
    Response<_tds__GetUsersResponse> GetUsers(Request<_tds__GetUsers> &request) const;
    Response<_tds__CreateUsersResponse> CreateUsers(Request<_tds__CreateUsers> &request) const;
    Response<_tds__DeleteUsersResponse> DeleteUsers(Request<_tds__DeleteUsers> &request) const;
    Response<_tds__SetUserResponse> SetUser(Request<_tds__SetUser> &request) const;
    Response<_tds__GetWsdlUrlResponse> GetWsdlUrl(Request<_tds__GetWsdlUrl> &request) const;
    Response<_tds__GetCapabilitiesResponse> GetCapabilities(Request<_tds__GetCapabilities> &request) const;
    Response<_tds__SetDPAddressesResponse> SetDPAddresses(Request<_tds__SetDPAddresses> &request) const;
    Response<_tds__GetHostnameResponse> GetHostname(Request<_tds__GetHostname> &request) const;
    Response<_tds__SetHostnameResponse> SetHostname(Request<_tds__SetHostname> &request) const;
    Response<_tds__SetHostnameFromDHCPResponse> SetHostnameFromDHCP(Request<_tds__SetHostnameFromDHCP> &request) const;
    Response<_tds__GetDNSResponse> GetDNS(Request<_tds__GetDNS> &request) const;
    Response<_tds__SetDNSResponse> SetDNS(Request<_tds__SetDNS> &request) const;
    Response<_tds__GetNTPResponse> GetNTP(Request<_tds__GetNTP> &request) const;
    Response<_tds__SetNTPResponse> SetNTP(Request<_tds__SetNTP> &request) const;
    Response<_tds__GetDynamicDNSResponse> GetDynamicDNS(Request<_tds__GetDynamicDNS> &request) const;
    Response<_tds__SetDynamicDNSResponse> SetDynamicDNS(Request<_tds__SetDynamicDNS> &request) const;
    Response<_tds__GetNetworkInterfacesResponse> GetNetworkInterfaces(Request<_tds__GetNetworkInterfaces> &request) const;
    Response<_tds__SetNetworkInterfacesResponse> SetNetworkInterfaces(Request<_tds__SetNetworkInterfaces> &request) const;
    Response<_tds__GetNetworkProtocolsResponse> GetNetworkProtocols(Request<_tds__GetNetworkProtocols> &request) const;
    Response<_tds__SetNetworkProtocolsResponse> SetNetworkProtocols(Request<_tds__SetNetworkProtocols> &request) const;
    Response<_tds__GetNetworkDefaultGatewayResponse> GetNetworkDefaultGateway(Request<_tds__GetNetworkDefaultGateway> &request) const;
    Response<_tds__SetNetworkDefaultGatewayResponse> SetNetworkDefaultGateway(Request<_tds__SetNetworkDefaultGateway> &request) const;
    Response<_tds__GetZeroConfigurationResponse> GetZeroConfiguration(Request<_tds__GetZeroConfiguration> &request) const;
    Response<_tds__SetZeroConfigurationResponse> SetZeroConfiguration(Request<_tds__SetZeroConfiguration> &request) const;
    Response<_tds__GetIPAddressFilterResponse> GetIPAddressFilter(Request<_tds__GetIPAddressFilter> &request) const;
    Response<_tds__SetIPAddressFilterResponse> SetIPAddressFilter(Request<_tds__SetIPAddressFilter> &request) const;
    Response<_tds__AddIPAddressFilterResponse> AddIPAddressFilter(Request<_tds__AddIPAddressFilter> &request) const;
    Response<_tds__RemoveIPAddressFilterResponse> RemoveIPAddressFilter(Request<_tds__RemoveIPAddressFilter> &request) const;
    Response<_tds__GetAccessPolicyResponse> GetAccessPolicy(Request<_tds__GetAccessPolicy> &request) const;
    Response<_tds__SetAccessPolicyResponse> SetAccessPolicy(Request<_tds__SetAccessPolicy> &request) const;
    Response<_tds__CreateCertificateResponse> CreateCertificate(Request<_tds__CreateCertificate> &request) const;
    Response<_tds__GetCertificatesResponse> GetCertificates(Request<_tds__GetCertificates> &request) const;
    Response<_tds__GetCertificatesStatusResponse> GetCertificatesStatus(Request<_tds__GetCertificatesStatus> &request) const;
    Response<_tds__SetCertificatesStatusResponse> SetCertificatesStatus(Request<_tds__SetCertificatesStatus> &request) const;
    Response<_tds__DeleteCertificatesResponse> DeleteCertificates(Request<_tds__DeleteCertificates> &request) const;
    Response<_tds__GetPkcs10RequestResponse> GetPkcs10Request(Request<_tds__GetPkcs10Request> &request) const;
    Response<_tds__LoadCertificatesResponse> LoadCertificates(Request<_tds__LoadCertificates> &request) const;
    Response<_tds__GetClientCertificateModeResponse> GetClientCertificateMode(Request<_tds__GetClientCertificateMode> &request) const;
    Response<_tds__SetClientCertificateModeResponse> SetClientCertificateMode(Request<_tds__SetClientCertificateMode> &request) const;
    Response<_tds__GetRelayOutputsResponse> GetRelayOutputs(Request<_tds__GetRelayOutputs> &request) const;
    Response<_tds__SetRelayOutputSettingsResponse> SetRelayOutputSettings(Request<_tds__SetRelayOutputSettings> &request) const;
    Response<_tds__SetRelayOutputStateResponse> SetRelayOutputState(Request<_tds__SetRelayOutputState> &request) const;
    Response<_tds__SendAuxiliaryCommandResponse> SendAuxiliaryCommand(Request<_tds__SendAuxiliaryCommand> &request) const;
    Response<_tds__GetCACertificatesResponse> GetCACertificates(Request<_tds__GetCACertificates> &request) const;
    Response<_tds__LoadCertificateWithPrivateKeyResponse> LoadCertificateWithPrivateKey(Request<_tds__LoadCertificateWithPrivateKey> &request) const;
    Response<_tds__GetCertificateInformationResponse> GetCertificateInformation(Request<_tds__GetCertificateInformation> &request) const;
    Response<_tds__LoadCACertificatesResponse> LoadCACertificates(Request<_tds__LoadCACertificates> &request) const;
    Response<_tds__CreateDot1XConfigurationResponse> CreateDot1XConfiguration(Request<_tds__CreateDot1XConfiguration> &request) const;
    Response<_tds__SetDot1XConfigurationResponse> SetDot1XConfiguration(Request<_tds__SetDot1XConfiguration> &request) const;
    Response<_tds__GetDot1XConfigurationResponse> GetDot1XConfiguration(Request<_tds__GetDot1XConfiguration> &request) const;
    Response<_tds__GetDot1XConfigurationsResponse> GetDot1XConfigurations(Request<_tds__GetDot1XConfigurations> &request) const;
    Response<_tds__DeleteDot1XConfigurationResponse> DeleteDot1XConfiguration(Request<_tds__DeleteDot1XConfiguration> &request) const;
    Response<_tds__GetDot11CapabilitiesResponse> GetDot11Capabilities(Request<_tds__GetDot11Capabilities> &request) const;
    Response<_tds__GetDot11StatusResponse> GetDot11Status(Request<_tds__GetDot11Status> &request) const;
    Response<_tds__ScanAvailableDot11NetworksResponse> ScanAvailableDot11Networks(Request<_tds__ScanAvailableDot11Networks> &request) const;
    Response<_tds__GetSystemUrisResponse> GetSystemUris(Request<_tds__GetSystemUris> &request) const;
    Response<_tds__StartFirmwareUpgradeResponse> StartFirmwareUpgrade(Request<_tds__StartFirmwareUpgrade> &request) const;
    Response<_tds__StartSystemRestoreResponse> StartSystemRestore(Request<_tds__StartSystemRestore> &request) const;
    Response<_tds__GetStorageConfigurationsResponse> GetStorageConfigurations(Request<_tds__GetStorageConfigurations> &request) const;
    Response<_tds__CreateStorageConfigurationResponse> CreateStorageConfiguration(Request<_tds__CreateStorageConfiguration> &request) const;
    Response<_tds__GetStorageConfigurationResponse> GetStorageConfiguration(Request<_tds__GetStorageConfiguration> &request) const;
    Response<_tds__SetStorageConfigurationResponse> SetStorageConfiguration(Request<_tds__SetStorageConfiguration> &request) const;
    Response<_tds__DeleteStorageConfigurationResponse> DeleteStorageConfiguration(Request<_tds__DeleteStorageConfiguration> &request) const;
    Response<_tds__GetGeoLocationResponse> GetGeoLocation(Request<_tds__GetGeoLocation> &request) const;
    Response<_tds__SetGeoLocationResponse> SetGeoLocation(Request<_tds__SetGeoLocation> &request) const;
    Response<_tds__DeleteGeoLocationResponse> DeleteGeoLocation(Request<_tds__DeleteGeoLocation> &request) const;
private:
    OnvifDeviceClientImplementation* impl_;
};


#endif //ONVIF_DEVICE_CLIENT_H
