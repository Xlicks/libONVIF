//
// Created by licks on 25-7-3.
//

#include "onvif_event_client.h"

#include "soapPullPointSubscriptionBindingProxy.h"

struct OnvifEventClientImplementation
{
    explicit OnvifEventClientImplementation(OnvifEventClient* ec_ptr)
        : event_client_ptr(ec_ptr),
          event_proxy(event_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(event_proxy.soap, SoapContext::GetDefaultNamespaces());
        ec_ptr->GetContext()->Release();
    }
    ~OnvifEventClientImplementation() = default;
    OnvifEventClient* event_client_ptr;
    PullPointSubscriptionBindingProxy event_proxy;
};
