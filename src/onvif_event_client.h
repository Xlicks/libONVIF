//
// Created by licks on 25-7-3.
//

#ifndef ONVIF_EVENT_CLIENT_H
#define ONVIF_EVENT_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"
#include "topics.h"

struct OnvifEventClientImplementation;

class OnvifEventClient final : public OnvifClient
{
public:
    DISALLOW_COPY_AND_ASSIGN(OnvifEventClient);
    explicit OnvifEventClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifEventClient() override;
    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver10/events/wsdl"; }
    Response<_tev__CreatePullPointSubscriptionResponse> CreatePullPointSubscription(Request<_tev__CreatePullPointSubscription> &request) const;
    Response<_tev__PullMessagesResponse> PullMessages(Request<_tev__PullMessages> &request) const;
    Response<_wsnt__RenewResponse> Renew(Request<_wsnt__Renew> &request) const;
    Response<_tev__SeekResponse> Seek(Request<_tev__Seek> &request, const std::string &rEndpoint) const;
    Response<_wsnt__UnsubscribeResponse> Unsubscribe(Request<_wsnt__Unsubscribe> &request) const;
    Response<_tev__SetSynchronizationPointResponse> SetSynchronizationPoint(Request<_tev__SetSynchronizationPoint> &request) const;
    Response<_tev__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_tev__GetServiceCapabilities> &request) const;
    Response<_tev__GetEventPropertiesResponse> GetEventProperties(Request<_tev__GetEventProperties> &request) const;
    //! Get a parsed version of a topic set
    ArbitraryResponse<TopicSet> GetParsedEventProperties(Request<_tev__GetEventProperties> &request);
    Response<_wsnt__SubscribeResponse> Subscribe(Request<_wsnt__Subscribe> &request) const;
    Response<_wsnt__GetCurrentMessageResponse> GetCurrentMessage(Request<_wsnt__GetCurrentMessage> &request) const;
    SimpleResponse send_Notify(Request<_wsnt__Notify> &request) const;
    [[nodiscard]] Response<_wsnt__Notify> recv_Notify() const;
    [[nodiscard]] SimpleResponse recv_Notify_empty_response() const;
    SimpleResponse Notify(Request<_wsnt__Notify> &request) const;
    Response<_wsnt__GetMessagesResponse> GetMessages(Request<_wsnt__GetMessages> &request) const;
    Response<_wsnt__DestroyPullPointResponse> DestroyPullPoint(Request<_wsnt__DestroyPullPoint> &request) const;
    Response<_wsnt__PauseSubscriptionResponse> PauseSubscription(Request<_wsnt__PauseSubscription> &request) const;
    Response<_wsnt__ResumeSubscriptionResponse> ResumeSubscription(Request<_wsnt__ResumeSubscription> &request) const;
private:
    OnvifEventClientImplementation* impl_;
};


#endif //ONVIF_EVENT_CLIENT_H
