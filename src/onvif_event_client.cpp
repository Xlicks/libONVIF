//
// Created by licks on 25-7-3.
//

#include "onvif_event_client.h"

#include <utility>

#include "soapPullPointSubscriptionBindingProxy.h"
#include "wsaapi.h"

struct OnvifEventClientImplementation
{
    explicit OnvifEventClientImplementation(OnvifEventClient* ec_ptr)
        : event_client_ptr(ec_ptr),
          event_proxy(event_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(event_proxy.soap, SoapContext::GetDefaultNamespaces());
        event_client_ptr->GetContext()->Release();
    }
    ~OnvifEventClientImplementation() = default;
    OnvifEventClient* event_client_ptr;
    PullPointSubscriptionBindingProxy event_proxy;
};

OnvifEventClient::OnvifEventClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
    : OnvifClient(endpoint, std::move(shared_ctx)),
      impl_(new (std::nothrow) OnvifEventClientImplementation(this))
{
}

OnvifEventClient::~OnvifEventClient()
{
    delete impl_;
}

Response<_tev__CreatePullPointSubscriptionResponse> OnvifEventClient::CreatePullPointSubscription(
    Request<_tev__CreatePullPointSubscription>& request) const
{
    _tev__CreatePullPointSubscriptionResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/EventPortType/CreatePullPointSubscriptionRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.CreatePullPointSubscription(GetEndpoint().c_str(), !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tev__CreatePullPointSubscriptionResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tev__PullMessagesResponse> OnvifEventClient::PullMessages(Request<_tev__PullMessages>& request) const
{
    _tev__PullMessagesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/PullPointSubscription/PullMessagesRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.PullMessages(GetEndpoint().c_str(), !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tev__PullMessagesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__RenewResponse> OnvifEventClient::Renew(Request<_wsnt__Renew>& request) const
{
    _wsnt__RenewResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/SubscriptionManager/RenewRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.Renew(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_wsnt__RenewResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tev__SeekResponse> OnvifEventClient::Seek(Request<_tev__Seek>& request, const std::string& rEndpoint) const
{
    _tev__SeekResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/PullPointSubscription/SeekRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), rEndpoint.c_str(), action);
        impl_->event_proxy.Seek(rEndpoint.c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tev__SeekResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__UnsubscribeResponse> OnvifEventClient::Unsubscribe(Request<_wsnt__Unsubscribe>& request) const
{
    _wsnt__UnsubscribeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/SubscriptionManager/UnsubscribeRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.Unsubscribe(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_wsnt__UnsubscribeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tev__SetSynchronizationPointResponse> OnvifEventClient::SetSynchronizationPoint(
    Request<_tev__SetSynchronizationPoint>& request) const
{
    _tev__SetSynchronizationPointResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/PullPointSubscription/SetSynchronizationPointRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.SetSynchronizationPoint(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tev__SetSynchronizationPointResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tev__GetServiceCapabilitiesResponse> OnvifEventClient::GetServiceCapabilities(
    Request<_tev__GetServiceCapabilities>& request) const
{
    _tev__GetServiceCapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/EventPortType/GetServiceCapabilitiesRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.GetServiceCapabilities(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_tev__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_tev__GetEventPropertiesResponse> OnvifEventClient::GetEventProperties(
    Request<_tev__GetEventProperties>& request) const
{
    _tev__GetEventPropertiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://www.onvif.org/ver10/events/wsdl/EventPortType/GetEventPropertiesRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.GetEventProperties(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_tev__GetEventPropertiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

ArbitraryResponse<TopicSet> OnvifEventClient::GetParsedEventProperties(Request<_tev__GetEventProperties>& request)
{
    //TODO
}

Response<_wsnt__SubscribeResponse> OnvifEventClient::Subscribe(Request<_wsnt__Subscribe>& request) const
{
    _wsnt__SubscribeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/NotificationProducer/SubscribeRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.Subscribe(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    } while(ReTry(soap_ptr));
    auto response = Response<_wsnt__SubscribeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__GetCurrentMessageResponse> OnvifEventClient::GetCurrentMessage(
    Request<_wsnt__GetCurrentMessage>& request) const
{
    _wsnt__GetCurrentMessageResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/NotificationProducer/GetCurrentMessageRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.GetCurrentMessage(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_wsnt__GetCurrentMessageResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

SimpleResponse OnvifEventClient::send_Notify(Request<_wsnt__Notify>& request) const
{
    auto ret = SOAP_OK;
    const auto soap_ptr = AcquireContext();
    do {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/NotificationConsumer/Notify";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        ret = impl_->event_proxy.send_Notify(GetEndpoint().c_str(), action, &request);
    } while(ReTry(soap_ptr));
    SimpleResponse response(ret, impl_->event_proxy.soap_fault_string(), impl_->event_proxy.soap_fault_detail());
    ReleaseContext(soap_ptr);
    return response;
}

Response<_wsnt__Notify> OnvifEventClient::recv_Notify() const
{
    __tev__Notify response_object;
    auto ret = SOAP_OK;
    const auto soap_ptr = AcquireContext();
    do
    {
        ret = impl_->event_proxy.recv_Notify(response_object);
    } while(ReTry(soap_ptr));
    Response<_wsnt__Notify> response(ret, impl_->event_proxy.soap_fault_string(), impl_->event_proxy.soap_fault_detail(), ret == SOAP_OK && response_object.wsnt__Notify ? response_object.wsnt__Notify->soap_dup() : nullptr);
    ReleaseContext(soap_ptr);
    return response;
}

SimpleResponse OnvifEventClient::recv_Notify_empty_response() const
{
    auto ret = SOAP_OK;
    const auto soap_ptr = AcquireContext();
    do
    {
        ret = impl_->event_proxy.recv_Notify_empty_response();
    } while(ReTry(soap_ptr));
    SimpleResponse response(ret, impl_->event_proxy.soap_fault_string(), impl_->event_proxy.soap_fault_detail());
    ReleaseContext(soap_ptr);
    return response;
}

SimpleResponse OnvifEventClient::Notify(Request<_wsnt__Notify>& request) const
{
    auto ret = SOAP_OK;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/NotificationConsumer/Notify";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        ret = impl_->event_proxy.Notify(GetEndpoint().c_str(), action, &request);
    } while(ReTry(soap_ptr));
    SimpleResponse response(ret, impl_->event_proxy.soap_fault_string(), impl_->event_proxy.soap_fault_detail());
    ReleaseContext(soap_ptr);
    return response;
}

Response<_wsnt__GetMessagesResponse> OnvifEventClient::GetMessages(Request<_wsnt__GetMessages>& request) const
{
    _wsnt__GetMessagesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/PullPoint/GetMessagesRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.GetMessages(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_wsnt__GetMessagesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__DestroyPullPointResponse> OnvifEventClient::DestroyPullPoint(
    Request<_wsnt__DestroyPullPoint>& request) const
{
    _wsnt__DestroyPullPointResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/PullPoint/DestroyPullPointRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.DestroyPullPoint(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_wsnt__DestroyPullPointResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__PauseSubscriptionResponse> OnvifEventClient::PauseSubscription(
    Request<_wsnt__PauseSubscription>& request) const
{
    _wsnt__PauseSubscriptionResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/PausableSubscriptionManager/PauseSubscriptionRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.PauseSubscription(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_wsnt__PauseSubscriptionResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_wsnt__ResumeSubscriptionResponse> OnvifEventClient::ResumeSubscription(
    Request<_wsnt__ResumeSubscription>& request) const
{
    _wsnt__ResumeSubscriptionResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        const auto action = "http://docs.oasis-open.org/wsn/bw-2/PausableSubscriptionManager/ResumeSubscriptionRequest";
        soap_wsa_request(soap_ptr, soap_wsa_rand_uuid(soap_ptr), GetEndpoint().c_str(), action);
        impl_->event_proxy.ResumeSubscription(GetEndpoint().c_str(),!request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr, &request, response_object);
    }while(ReTry(soap_ptr));
    auto response = Response<_wsnt__ResumeSubscriptionResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}
