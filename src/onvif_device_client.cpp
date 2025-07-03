//
// Created by licks on 24-7-2.
//

#include "onvif_device_client.h"
#include "soapDeviceBindingProxy.h"

struct OnvifDeviceClientImplementation
{
    explicit OnvifDeviceClientImplementation(OnvifDeviceClient* device_client) : device_client_ptr(device_client),
        device_proxy(device_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(device_proxy.soap, SoapContext::GetDefaultNamespaces());
        device_client_ptr->GetContext()->Release();
    }

    OnvifDeviceClient* device_client_ptr;
    DeviceBindingProxy device_proxy;
};

OnvifDeviceClient::OnvifDeviceClient(const std::string& endpoint, std::shared_ptr<SoapContext> soap_ctx)
        : OnvifClient(endpoint, std::move(soap_ctx)), impl_(new (std::nothrow) OnvifDeviceClientImplementation(this))
{
}

OnvifDeviceClient::~OnvifDeviceClient()
{
    delete impl_;
}

Response<_tds__GetServicesResponse> OnvifDeviceClient::GetServices(Request<_tds__GetServices>& request) const
{
    _tds__GetServicesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetServices(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetServicesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetServiceCapabilitiesResponse> OnvifDeviceClient::GetServiceCapabilities(
    Request<_tds__GetServiceCapabilities>& request) const
{
    _tds__GetServiceCapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetServiceCapabilities(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDeviceInformationResponse> OnvifDeviceClient::GetDeviceInformation(
    Request<_tds__GetDeviceInformation>& request) const
{
    _tds__GetDeviceInformationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDeviceInformation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDeviceInformationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetSystemDateAndTimeResponse> OnvifDeviceClient::SetSystemDateAndTime(
    Request<_tds__SetSystemDateAndTime>& request) const
{
    _tds__SetSystemDateAndTimeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetSystemDateAndTime(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetSystemDateAndTimeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetSystemDateAndTimeResponse> OnvifDeviceClient::GetSystemDateAndTime(
    Request<_tds__GetSystemDateAndTime>& request) const
{
    _tds__GetSystemDateAndTimeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetSystemDateAndTime(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetSystemDateAndTimeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetSystemFactoryDefaultResponse> OnvifDeviceClient::SetSystemFactoryDefault(
    Request<_tds__SetSystemFactoryDefault>& request) const
{
    _tds__SetSystemFactoryDefaultResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetSystemFactoryDefault(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetSystemFactoryDefaultResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__UpgradeSystemFirmwareResponse> OnvifDeviceClient::UpgradeSystemFirmware(
    Request<_tds__UpgradeSystemFirmware>& request) const
{
    _tds__UpgradeSystemFirmwareResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.UpgradeSystemFirmware(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__UpgradeSystemFirmwareResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SystemRebootResponse> OnvifDeviceClient::SystemReboot(Request<_tds__SystemReboot>& request) const
{
    _tds__SystemRebootResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SystemReboot(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SystemRebootResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__RestoreSystemResponse> OnvifDeviceClient::RestoreSystem(Request<_tds__RestoreSystem>& request) const
{
    _tds__RestoreSystemResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.RestoreSystem(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__RestoreSystemResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetSystemBackupResponse> OnvifDeviceClient::GetSystemBackup(
    Request<_tds__GetSystemBackup>& request) const
{
    _tds__GetSystemBackupResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetSystemBackup(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetSystemBackupResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetSystemLogResponse> OnvifDeviceClient::GetSystemLog(Request<_tds__GetSystemLog>& request) const
{
    _tds__GetSystemLogResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetSystemLog(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetSystemLogResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetSystemSupportInformationResponse> OnvifDeviceClient::GetSystemSupportInformation(
    Request<_tds__GetSystemSupportInformation>& request) const
{
    _tds__GetSystemSupportInformationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetSystemSupportInformation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetSystemSupportInformationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetScopesResponse> OnvifDeviceClient::GetScopes(Request<_tds__GetScopes>& request) const
{
    _tds__GetScopesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetScopes(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetScopesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetScopesResponse> OnvifDeviceClient::SetScopes(Request<_tds__SetScopes>& request) const
{
    _tds__SetScopesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetScopes(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetScopesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__AddScopesResponse> OnvifDeviceClient::AddScopes(Request<_tds__AddScopes>& request) const
{
    _tds__AddScopesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.AddScopes(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__AddScopesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__RemoveScopesResponse> OnvifDeviceClient::RemoveScopes(Request<_tds__RemoveScopes>& request) const
{
    _tds__RemoveScopesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.RemoveScopes(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__RemoveScopesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDiscoveryModeResponse> OnvifDeviceClient::GetDiscoveryMode(
    Request<_tds__GetDiscoveryMode>& request) const
{
    _tds__GetDiscoveryModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDiscoveryMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDiscoveryModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetDiscoveryModeResponse> OnvifDeviceClient::SetDiscoveryMode(
    Request<_tds__SetDiscoveryMode>& request) const
{
    _tds__SetDiscoveryModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetDiscoveryMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetDiscoveryModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetRemoteDiscoveryModeResponse> OnvifDeviceClient::GetRemoteDiscoveryMode(
    Request<_tds__GetRemoteDiscoveryMode>& request) const
{
    _tds__GetRemoteDiscoveryModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetRemoteDiscoveryMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetRemoteDiscoveryModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetRemoteDiscoveryModeResponse> OnvifDeviceClient::SetRemoteDiscoveryMode(
    Request<_tds__SetRemoteDiscoveryMode>& request) const
{
    _tds__SetRemoteDiscoveryModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetRemoteDiscoveryMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetRemoteDiscoveryModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDPAddressesResponse> OnvifDeviceClient::GetDPAddresses(Request<_tds__GetDPAddresses>& request) const
{
    _tds__GetDPAddressesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDPAddresses(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDPAddressesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetEndpointReferenceResponse> OnvifDeviceClient::GetEndpointReference(
    Request<_tds__GetEndpointReference>& request) const
{
    _tds__GetEndpointReferenceResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetEndpointReference(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetEndpointReferenceResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetRemoteUserResponse> OnvifDeviceClient::GetRemoteUser(Request<_tds__GetRemoteUser>& request) const
{
    _tds__GetRemoteUserResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetRemoteUser(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetRemoteUserResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetRemoteUserResponse> OnvifDeviceClient::SetRemoteUser(Request<_tds__SetRemoteUser>& request) const
{
    _tds__SetRemoteUserResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetRemoteUser(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetRemoteUserResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetUsersResponse> OnvifDeviceClient::GetUsers(Request<_tds__GetUsers>& request) const
{
    _tds__GetUsersResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetUsers(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetUsersResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__CreateUsersResponse> OnvifDeviceClient::CreateUsers(Request<_tds__CreateUsers>& request) const
{
    _tds__CreateUsersResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.CreateUsers(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__CreateUsersResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__DeleteUsersResponse> OnvifDeviceClient::DeleteUsers(Request<_tds__DeleteUsers>& request) const
{
    _tds__DeleteUsersResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.DeleteUsers(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__DeleteUsersResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetUserResponse> OnvifDeviceClient::SetUser(Request<_tds__SetUser>& request) const
{
    _tds__SetUserResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetUser(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetUserResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetWsdlUrlResponse> OnvifDeviceClient::GetWsdlUrl(Request<_tds__GetWsdlUrl>& request) const
{
    _tds__GetWsdlUrlResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetWsdlUrl(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetWsdlUrlResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetCapabilitiesResponse> OnvifDeviceClient::GetCapabilities(Request<_tds__GetCapabilities>& request) const
{
    _tds__GetCapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetCapabilities(GetEndpoint().c_str(), !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetDPAddressesResponse> OnvifDeviceClient::SetDPAddresses(Request<_tds__SetDPAddresses>& request) const
{
    _tds__SetDPAddressesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetDPAddresses(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetDPAddressesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetHostnameResponse> OnvifDeviceClient::GetHostname(Request<_tds__GetHostname>& request) const
{
    _tds__GetHostnameResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetHostname(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetHostnameResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetHostnameResponse> OnvifDeviceClient::SetHostname(Request<_tds__SetHostname>& request) const
{
    _tds__SetHostnameResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetHostname(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetHostnameResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetHostnameFromDHCPResponse> OnvifDeviceClient::SetHostnameFromDHCP(
    Request<_tds__SetHostnameFromDHCP>& request) const
{
    _tds__SetHostnameFromDHCPResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetHostnameFromDHCP(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetHostnameFromDHCPResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDNSResponse> OnvifDeviceClient::GetDNS(Request<_tds__GetDNS>& request) const
{
    _tds__GetDNSResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDNS(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDNSResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetDNSResponse> OnvifDeviceClient::SetDNS(Request<_tds__SetDNS>& request) const
{
    _tds__SetDNSResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetDNS(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetDNSResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetNTPResponse> OnvifDeviceClient::GetNTP(Request<_tds__GetNTP>& request) const
{
    _tds__GetNTPResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetNTP(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetNTPResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetNTPResponse> OnvifDeviceClient::SetNTP(Request<_tds__SetNTP>& request) const
{
    _tds__SetNTPResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetNTP(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetNTPResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDynamicDNSResponse> OnvifDeviceClient::GetDynamicDNS(Request<_tds__GetDynamicDNS>& request) const
{
    _tds__GetDynamicDNSResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDynamicDNS(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDynamicDNSResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetDynamicDNSResponse> OnvifDeviceClient::SetDynamicDNS(Request<_tds__SetDynamicDNS>& request) const
{
    _tds__SetDynamicDNSResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetDynamicDNS(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetDynamicDNSResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetNetworkInterfacesResponse> OnvifDeviceClient::GetNetworkInterfaces(
    Request<_tds__GetNetworkInterfaces>& request) const
{
    _tds__GetNetworkInterfacesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetNetworkInterfaces(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetNetworkInterfacesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetNetworkInterfacesResponse> OnvifDeviceClient::SetNetworkInterfaces(
    Request<_tds__SetNetworkInterfaces>& request) const
{
    _tds__SetNetworkInterfacesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetNetworkInterfaces(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetNetworkInterfacesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetNetworkProtocolsResponse> OnvifDeviceClient::GetNetworkProtocols(
    Request<_tds__GetNetworkProtocols>& request) const
{
    _tds__GetNetworkProtocolsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetNetworkProtocols(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetNetworkProtocolsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetNetworkProtocolsResponse> OnvifDeviceClient::SetNetworkProtocols(
    Request<_tds__SetNetworkProtocols>& request) const
{
    _tds__SetNetworkProtocolsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetNetworkProtocols(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetNetworkProtocolsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetNetworkDefaultGatewayResponse> OnvifDeviceClient::GetNetworkDefaultGateway(
    Request<_tds__GetNetworkDefaultGateway>& request) const
{
    _tds__GetNetworkDefaultGatewayResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetNetworkDefaultGateway(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetNetworkDefaultGatewayResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetNetworkDefaultGatewayResponse> OnvifDeviceClient::SetNetworkDefaultGateway(
    Request<_tds__SetNetworkDefaultGateway>& request) const
{
    _tds__SetNetworkDefaultGatewayResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetNetworkDefaultGateway(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetNetworkDefaultGatewayResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetZeroConfigurationResponse> OnvifDeviceClient::GetZeroConfiguration(
    Request<_tds__GetZeroConfiguration>& request) const
{
    _tds__GetZeroConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetZeroConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetZeroConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetZeroConfigurationResponse> OnvifDeviceClient::SetZeroConfiguration(
    Request<_tds__SetZeroConfiguration>& request) const
{
    _tds__SetZeroConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetZeroConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetZeroConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetIPAddressFilterResponse> OnvifDeviceClient::GetIPAddressFilter(
    Request<_tds__GetIPAddressFilter>& request) const
{
    _tds__GetIPAddressFilterResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetIPAddressFilter(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetIPAddressFilterResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetIPAddressFilterResponse> OnvifDeviceClient::SetIPAddressFilter(
    Request<_tds__SetIPAddressFilter>& request) const
{
    _tds__SetIPAddressFilterResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetIPAddressFilter(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetIPAddressFilterResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__AddIPAddressFilterResponse> OnvifDeviceClient::AddIPAddressFilter(
    Request<_tds__AddIPAddressFilter>& request) const
{
    _tds__AddIPAddressFilterResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.AddIPAddressFilter(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__AddIPAddressFilterResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__RemoveIPAddressFilterResponse> OnvifDeviceClient::RemoveIPAddressFilter(
    Request<_tds__RemoveIPAddressFilter>& request) const
{
    _tds__RemoveIPAddressFilterResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.RemoveIPAddressFilter(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__RemoveIPAddressFilterResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetAccessPolicyResponse> OnvifDeviceClient::GetAccessPolicy(
    Request<_tds__GetAccessPolicy>& request) const
{
    _tds__GetAccessPolicyResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetAccessPolicy(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetAccessPolicyResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetAccessPolicyResponse> OnvifDeviceClient::SetAccessPolicy(
    Request<_tds__SetAccessPolicy>& request) const
{
    _tds__SetAccessPolicyResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetAccessPolicy(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetAccessPolicyResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__CreateCertificateResponse> OnvifDeviceClient::CreateCertificate(
    Request<_tds__CreateCertificate>& request) const
{
    _tds__CreateCertificateResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.CreateCertificate(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__CreateCertificateResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetCertificatesResponse> OnvifDeviceClient::GetCertificates(
    Request<_tds__GetCertificates>& request) const
{
    _tds__GetCertificatesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetCertificates(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetCertificatesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetCertificatesStatusResponse> OnvifDeviceClient::GetCertificatesStatus(
    Request<_tds__GetCertificatesStatus>& request) const
{
    _tds__GetCertificatesStatusResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetCertificatesStatus(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetCertificatesStatusResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetCertificatesStatusResponse> OnvifDeviceClient::SetCertificatesStatus(
    Request<_tds__SetCertificatesStatus>& request) const
{
    _tds__SetCertificatesStatusResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetCertificatesStatus(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetCertificatesStatusResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__DeleteCertificatesResponse> OnvifDeviceClient::DeleteCertificates(
    Request<_tds__DeleteCertificates>& request) const
{
    _tds__DeleteCertificatesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.DeleteCertificates(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__DeleteCertificatesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetPkcs10RequestResponse> OnvifDeviceClient::GetPkcs10Request(
    Request<_tds__GetPkcs10Request>& request) const
{
    _tds__GetPkcs10RequestResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetPkcs10Request(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetPkcs10RequestResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__LoadCertificatesResponse> OnvifDeviceClient::LoadCertificates(
    Request<_tds__LoadCertificates>& request) const
{
    _tds__LoadCertificatesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.LoadCertificates(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__LoadCertificatesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetClientCertificateModeResponse> OnvifDeviceClient::GetClientCertificateMode(
    Request<_tds__GetClientCertificateMode>& request) const
{
    _tds__GetClientCertificateModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetClientCertificateMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetClientCertificateModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetClientCertificateModeResponse> OnvifDeviceClient::SetClientCertificateMode(
    Request<_tds__SetClientCertificateMode>& request) const
{
    _tds__SetClientCertificateModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetClientCertificateMode(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetClientCertificateModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetRelayOutputsResponse> OnvifDeviceClient::GetRelayOutputs(
    Request<_tds__GetRelayOutputs>& request) const
{
    _tds__GetRelayOutputsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetRelayOutputs(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetRelayOutputsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetRelayOutputSettingsResponse> OnvifDeviceClient::SetRelayOutputSettings(
    Request<_tds__SetRelayOutputSettings>& request) const
{
    _tds__SetRelayOutputSettingsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetRelayOutputSettings(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetRelayOutputSettingsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetRelayOutputStateResponse> OnvifDeviceClient::SetRelayOutputState(
    Request<_tds__SetRelayOutputState>& request) const
{
    _tds__SetRelayOutputStateResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetRelayOutputState(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetRelayOutputStateResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SendAuxiliaryCommandResponse> OnvifDeviceClient::SendAuxiliaryCommand(
    Request<_tds__SendAuxiliaryCommand>& request) const
{
    _tds__SendAuxiliaryCommandResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SendAuxiliaryCommand(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SendAuxiliaryCommandResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetCACertificatesResponse> OnvifDeviceClient::GetCACertificates(
    Request<_tds__GetCACertificates>& request) const
{
    _tds__GetCACertificatesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetCACertificates(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetCACertificatesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__LoadCertificateWithPrivateKeyResponse> OnvifDeviceClient::LoadCertificateWithPrivateKey(
    Request<_tds__LoadCertificateWithPrivateKey>& request) const
{
    _tds__LoadCertificateWithPrivateKeyResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.LoadCertificateWithPrivateKey(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__LoadCertificateWithPrivateKeyResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetCertificateInformationResponse> OnvifDeviceClient::GetCertificateInformation(
    Request<_tds__GetCertificateInformation>& request) const
{
    _tds__GetCertificateInformationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetCertificateInformation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetCertificateInformationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__LoadCACertificatesResponse> OnvifDeviceClient::LoadCACertificates(
    Request<_tds__LoadCACertificates>& request) const
{
    _tds__LoadCACertificatesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.LoadCACertificates(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__LoadCACertificatesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__CreateDot1XConfigurationResponse> OnvifDeviceClient::CreateDot1XConfiguration(
    Request<_tds__CreateDot1XConfiguration>& request) const
{
    _tds__CreateDot1XConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.CreateDot1XConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__CreateDot1XConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetDot1XConfigurationResponse> OnvifDeviceClient::SetDot1XConfiguration(
    Request<_tds__SetDot1XConfiguration>& request) const
{
    _tds__SetDot1XConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetDot1XConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetDot1XConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDot1XConfigurationResponse> OnvifDeviceClient::GetDot1XConfiguration(
    Request<_tds__GetDot1XConfiguration>& request) const
{
    _tds__GetDot1XConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDot1XConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDot1XConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDot1XConfigurationsResponse> OnvifDeviceClient::GetDot1XConfigurations(
    Request<_tds__GetDot1XConfigurations>& request) const
{
    _tds__GetDot1XConfigurationsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDot1XConfigurations(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDot1XConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__DeleteDot1XConfigurationResponse> OnvifDeviceClient::DeleteDot1XConfiguration(
    Request<_tds__DeleteDot1XConfiguration>& request) const
{
    _tds__DeleteDot1XConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.DeleteDot1XConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__DeleteDot1XConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDot11CapabilitiesResponse> OnvifDeviceClient::GetDot11Capabilities(
    Request<_tds__GetDot11Capabilities>& request) const
{
    _tds__GetDot11CapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDot11Capabilities(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDot11CapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetDot11StatusResponse> OnvifDeviceClient::GetDot11Status(Request<_tds__GetDot11Status>& request) const
{
    _tds__GetDot11StatusResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetDot11Status(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetDot11StatusResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__ScanAvailableDot11NetworksResponse> OnvifDeviceClient::ScanAvailableDot11Networks(
    Request<_tds__ScanAvailableDot11Networks>& request) const
{
    _tds__ScanAvailableDot11NetworksResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.ScanAvailableDot11Networks(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__ScanAvailableDot11NetworksResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetSystemUrisResponse> OnvifDeviceClient::GetSystemUris(Request<_tds__GetSystemUris>& request) const
{
    _tds__GetSystemUrisResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetSystemUris(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetSystemUrisResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__StartFirmwareUpgradeResponse> OnvifDeviceClient::StartFirmwareUpgrade(
    Request<_tds__StartFirmwareUpgrade>& request) const
{
    _tds__StartFirmwareUpgradeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.StartFirmwareUpgrade(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__StartFirmwareUpgradeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__StartSystemRestoreResponse> OnvifDeviceClient::StartSystemRestore(
    Request<_tds__StartSystemRestore>& request) const
{
    _tds__StartSystemRestoreResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.StartSystemRestore(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__StartSystemRestoreResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetStorageConfigurationsResponse> OnvifDeviceClient::GetStorageConfigurations(
    Request<_tds__GetStorageConfigurations>& request) const
{
    _tds__GetStorageConfigurationsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetStorageConfigurations(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetStorageConfigurationsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__CreateStorageConfigurationResponse> OnvifDeviceClient::CreateStorageConfiguration(
    Request<_tds__CreateStorageConfiguration>& request) const
{
    _tds__CreateStorageConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.CreateStorageConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__CreateStorageConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetStorageConfigurationResponse> OnvifDeviceClient::GetStorageConfiguration(
    Request<_tds__GetStorageConfiguration>& request) const
{
    _tds__GetStorageConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetStorageConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetStorageConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetStorageConfigurationResponse> OnvifDeviceClient::SetStorageConfiguration(
    Request<_tds__SetStorageConfiguration>& request) const
{
    _tds__SetStorageConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetStorageConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetStorageConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__DeleteStorageConfigurationResponse> OnvifDeviceClient::DeleteStorageConfiguration(
    Request<_tds__DeleteStorageConfiguration>& request) const
{
    _tds__DeleteStorageConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.DeleteStorageConfiguration(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__DeleteStorageConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__GetGeoLocationResponse> OnvifDeviceClient::GetGeoLocation(Request<_tds__GetGeoLocation>& request) const
{
    _tds__GetGeoLocationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.GetGeoLocation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__GetGeoLocationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__SetGeoLocationResponse> OnvifDeviceClient::SetGeoLocation(Request<_tds__SetGeoLocation>& request) const
{
    _tds__SetGeoLocationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.SetGeoLocation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__SetGeoLocationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tds__DeleteGeoLocationResponse> OnvifDeviceClient::DeleteGeoLocation(
    Request<_tds__DeleteGeoLocation>& request) const
{
    _tds__DeleteGeoLocationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->device_proxy.DeleteGeoLocation(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tds__DeleteGeoLocationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}
