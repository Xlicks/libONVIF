/* soapReceiverBindingService.cpp
   Generated by gSOAP 2.8.138 for generated.h

gSOAP XML Web services tools
Copyright (C) 2000-2025, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapReceiverBindingService.h"

ReceiverBindingService::ReceiverBindingService()
{	this->soap = soap_new();
	this->soap_own = true;
	ReceiverBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ReceiverBindingService::ReceiverBindingService(const ReceiverBindingService& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
}

ReceiverBindingService::ReceiverBindingService(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	ReceiverBindingService_init(_soap->imode, _soap->omode);
}

ReceiverBindingService::ReceiverBindingService(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	ReceiverBindingService_init(iomode, iomode);
}

ReceiverBindingService::ReceiverBindingService(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	ReceiverBindingService_init(imode, omode);
}

ReceiverBindingService::~ReceiverBindingService()
{	if (this->soap_own)
	{	ReceiverBindingService::destroy();
		soap_free(this->soap);
	}
}

void ReceiverBindingService::ReceiverBindingService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL },
        { "SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "c14n", "http://www.w3.org/2001/10/xml-exc-c14n#", NULL, NULL },
        { "ds", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL },
        { "saml1", "urn:oasis:names:tc:SAML:1.0:assertion", NULL, NULL },
        { "saml2", "urn:oasis:names:tc:SAML:2.0:assertion", NULL, NULL },
        { "wsu", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd", NULL, NULL },
        { "xenc", "http://www.w3.org/2001/04/xmlenc#", NULL, NULL },
        { "wsc", "http://docs.oasis-open.org/ws-sx/ws-secureconversation/200512", "http://schemas.xmlsoap.org/ws/2005/02/sc", NULL },
        { "wsse", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd", "http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd", NULL },
        { "chan", "http://schemas.microsoft.com/ws/2005/02/duplex", NULL, NULL },
        { "wsa5", "http://www.w3.org/2005/08/addressing", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL },
        { "wsrfr", "http://docs.oasis-open.org/wsrf/r-2", NULL, NULL },
        { "ns2", "http://www.onvif.org/ver20/analytics/humanface", NULL, NULL },
        { "ns3", "http://www.onvif.org/ver20/analytics/humanbody", NULL, NULL },
        { "xmime", "http://tempuri.org/xmime.xsd", NULL, NULL },
        { "xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL },
        { "tt", "http://www.onvif.org/ver10/schema", NULL, NULL },
        { "wsrfbf", "http://docs.oasis-open.org/wsrf/bf-2", NULL, NULL },
        { "wstop", "http://docs.oasis-open.org/wsn/t-1", NULL, NULL },
        { "ns1", "http://www.onvif.org/ver20/media/wsdl", NULL, NULL },
        { "tad", "http://www.onvif.org/ver10/analyticsdevice/wsdl", NULL, NULL },
        { "tan", "http://www.onvif.org/ver20/analytics/wsdl", NULL, NULL },
        { "tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL },
        { "tev", "http://www.onvif.org/ver10/events/wsdl", NULL, NULL },
        { "wsnt", "http://docs.oasis-open.org/wsn/b-2", NULL, NULL },
        { "timg", "http://www.onvif.org/ver20/imaging/wsdl", NULL, NULL },
        { "tls", "http://www.onvif.org/ver10/display/wsdl", NULL, NULL },
        { "tptz", "http://www.onvif.org/ver20/ptz/wsdl", NULL, NULL },
        { "trc", "http://www.onvif.org/ver10/recording/wsdl", NULL, NULL },
        { "trp", "http://www.onvif.org/ver10/replay/wsdl", NULL, NULL },
        { "trt", "http://www.onvif.org/ver10/media/wsdl", NULL, NULL },
        { "trv", "http://www.onvif.org/ver10/receiver/wsdl", NULL, NULL },
        { "tse", "http://www.onvif.org/ver10/search/wsdl", NULL, NULL },
        { NULL, NULL, NULL, NULL} /* end of namespaces[] */
    };
	soap_set_namespaces(this->soap, namespaces);
}

void ReceiverBindingService::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void ReceiverBindingService::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	ReceiverBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
ReceiverBindingService *ReceiverBindingService::copy()
{	ReceiverBindingService *dup = SOAP_NEW_UNMANAGED(ReceiverBindingService);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}
#endif

ReceiverBindingService& ReceiverBindingService::operator=(const ReceiverBindingService& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
	}
	return *this;
}

int ReceiverBindingService::soap_close_socket()
{	return soap_closesock(this->soap);
}

int ReceiverBindingService::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

int ReceiverBindingService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this->soap, string, detailXML);
}

int ReceiverBindingService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

int ReceiverBindingService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this->soap, string, detailXML);
}

int ReceiverBindingService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

void ReceiverBindingService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void ReceiverBindingService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *ReceiverBindingService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

void ReceiverBindingService::soap_noheader()
{	this->soap->header = NULL;
}

void ReceiverBindingService::soap_header(struct _wsse__Security *wsse__Security, char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance)
{
	::soap_header(this->soap);
	this->soap->header->wsse__Security = wsse__Security;
	this->soap->header->wsa5__MessageID = wsa5__MessageID;
	this->soap->header->wsa5__RelatesTo = wsa5__RelatesTo;
	this->soap->header->wsa5__From = wsa5__From;
	this->soap->header->wsa5__ReplyTo = wsa5__ReplyTo;
	this->soap->header->wsa5__FaultTo = wsa5__FaultTo;
	this->soap->header->wsa5__To = wsa5__To;
	this->soap->header->wsa5__Action = wsa5__Action;
	this->soap->header->chan__ChannelInstance = chan__ChannelInstance;
}

::SOAP_ENV__Header *ReceiverBindingService::soap_header()
{	return this->soap->header;
}

#ifndef WITH_NOIO
int ReceiverBindingService::run(int port, int backlog)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, backlog)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int ReceiverBindingService::ssl_run(int port, int backlog)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, backlog)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->ssl_accept() || this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}
#endif

SOAP_SOCKET ReceiverBindingService::bind(const char *host, int port, int backlog)
{	return soap_bind(this->soap, host, port, backlog);
}

SOAP_SOCKET ReceiverBindingService::accept()
{	return soap_accept(this->soap);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int ReceiverBindingService::ssl_accept()
{	return soap_ssl_accept(this->soap);
}
#endif
#endif

int ReceiverBindingService::serve()
{
#ifndef WITH_FASTCGI
	this->soap->keep_alive = this->soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (this->soap->keep_alive > 0 && this->soap->max_keep_alive > 0)
			this->soap->keep_alive--;
#endif
		if (soap_begin_serve(this->soap))
		{	if (this->soap->error >= SOAP_STOP)
				continue;
			return this->soap->error;
		}
		if ((dispatch() || (this->soap->fserveloop && this->soap->fserveloop(this->soap))) && this->soap->error && this->soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this->soap);
#else
			return soap_send_fault(this->soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(this->soap);
		soap_end(this->soap);
	} while (1);
#else
	} while (this->soap->keep_alive);
#endif
	return SOAP_OK;
}

static int serve___trv__GetServiceCapabilities(struct soap*, ReceiverBindingService*);
static int serve___trv__GetReceivers(struct soap*, ReceiverBindingService*);
static int serve___trv__GetReceiver(struct soap*, ReceiverBindingService*);
static int serve___trv__CreateReceiver(struct soap*, ReceiverBindingService*);
static int serve___trv__DeleteReceiver(struct soap*, ReceiverBindingService*);
static int serve___trv__ConfigureReceiver(struct soap*, ReceiverBindingService*);
static int serve___trv__SetReceiverMode(struct soap*, ReceiverBindingService*);
static int serve___trv__GetReceiverState(struct soap*, ReceiverBindingService*);

int ReceiverBindingService::dispatch()
{	return dispatch(this->soap);
}

int ReceiverBindingService::dispatch(struct soap* soap)
{
	ReceiverBindingService_init(soap->imode, soap->omode);
	if (soap->action)
	{
		const char *soap_action[] = { "http://www.onvif.org/ver10/receiver/wsdl/ConfigureReceiver", "http://www.onvif.org/ver10/receiver/wsdl/CreateReceiver", "http://www.onvif.org/ver10/receiver/wsdl/DeleteReceiver", "http://www.onvif.org/ver10/receiver/wsdl/GetReceiver", "http://www.onvif.org/ver10/receiver/wsdl/GetReceiverState", "http://www.onvif.org/ver10/receiver/wsdl/GetReceivers", "http://www.onvif.org/ver10/receiver/wsdl/GetServiceCapabilities", "http://www.onvif.org/ver10/receiver/wsdl/SetReceiverMode",  };
		switch (soap_binary_search_string(soap_action, 8, soap->action))
		{
			case 0:	
				return serve___trv__ConfigureReceiver(soap, this);
			case 1:	
				return serve___trv__CreateReceiver(soap, this);
			case 2:	
				return serve___trv__DeleteReceiver(soap, this);
			case 3:	
				return serve___trv__GetReceiver(soap, this);
			case 4:	
				return serve___trv__GetReceiverState(soap, this);
			case 5:	
				return serve___trv__GetReceivers(soap, this);
			case 6:	
				return serve___trv__GetServiceCapabilities(soap, this);
			case 7:	
				return serve___trv__SetReceiverMode(soap, this);
		}
	}
	(void)soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "trv:GetServiceCapabilities"))
		return serve___trv__GetServiceCapabilities(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:GetReceivers"))
		return serve___trv__GetReceivers(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:GetReceiver"))
		return serve___trv__GetReceiver(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:CreateReceiver"))
		return serve___trv__CreateReceiver(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:DeleteReceiver"))
		return serve___trv__DeleteReceiver(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:ConfigureReceiver"))
		return serve___trv__ConfigureReceiver(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:SetReceiverMode"))
		return serve___trv__SetReceiverMode(soap, this);
	if (!soap_match_tag(soap, soap->tag, "trv:GetReceiverState"))
		return serve___trv__GetReceiverState(soap, this);
	return soap->error = SOAP_NO_METHOD;
}

static int serve___trv__GetServiceCapabilities(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__GetServiceCapabilities soap_tmp___trv__GetServiceCapabilities;
	_trv__GetServiceCapabilitiesResponse trv__GetServiceCapabilitiesResponse;
	trv__GetServiceCapabilitiesResponse.soap_default(soap);
	soap_default___trv__GetServiceCapabilities(soap, &soap_tmp___trv__GetServiceCapabilities);
	if (!soap_get___trv__GetServiceCapabilities(soap, &soap_tmp___trv__GetServiceCapabilities, "-trv:GetServiceCapabilities", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetServiceCapabilities(soap_tmp___trv__GetServiceCapabilities.trv__GetServiceCapabilities, trv__GetServiceCapabilitiesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__GetServiceCapabilitiesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__GetServiceCapabilitiesResponse.soap_put(soap, "trv:GetServiceCapabilitiesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__GetServiceCapabilitiesResponse.soap_put(soap, "trv:GetServiceCapabilitiesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__GetReceivers(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__GetReceivers soap_tmp___trv__GetReceivers;
	_trv__GetReceiversResponse trv__GetReceiversResponse;
	trv__GetReceiversResponse.soap_default(soap);
	soap_default___trv__GetReceivers(soap, &soap_tmp___trv__GetReceivers);
	if (!soap_get___trv__GetReceivers(soap, &soap_tmp___trv__GetReceivers, "-trv:GetReceivers", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetReceivers(soap_tmp___trv__GetReceivers.trv__GetReceivers, trv__GetReceiversResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__GetReceiversResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__GetReceiversResponse.soap_put(soap, "trv:GetReceiversResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__GetReceiversResponse.soap_put(soap, "trv:GetReceiversResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__GetReceiver(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__GetReceiver soap_tmp___trv__GetReceiver;
	_trv__GetReceiverResponse trv__GetReceiverResponse;
	trv__GetReceiverResponse.soap_default(soap);
	soap_default___trv__GetReceiver(soap, &soap_tmp___trv__GetReceiver);
	if (!soap_get___trv__GetReceiver(soap, &soap_tmp___trv__GetReceiver, "-trv:GetReceiver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetReceiver(soap_tmp___trv__GetReceiver.trv__GetReceiver, trv__GetReceiverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__GetReceiverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__GetReceiverResponse.soap_put(soap, "trv:GetReceiverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__GetReceiverResponse.soap_put(soap, "trv:GetReceiverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__CreateReceiver(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__CreateReceiver soap_tmp___trv__CreateReceiver;
	_trv__CreateReceiverResponse trv__CreateReceiverResponse;
	trv__CreateReceiverResponse.soap_default(soap);
	soap_default___trv__CreateReceiver(soap, &soap_tmp___trv__CreateReceiver);
	if (!soap_get___trv__CreateReceiver(soap, &soap_tmp___trv__CreateReceiver, "-trv:CreateReceiver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->CreateReceiver(soap_tmp___trv__CreateReceiver.trv__CreateReceiver, trv__CreateReceiverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__CreateReceiverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__CreateReceiverResponse.soap_put(soap, "trv:CreateReceiverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__CreateReceiverResponse.soap_put(soap, "trv:CreateReceiverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__DeleteReceiver(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__DeleteReceiver soap_tmp___trv__DeleteReceiver;
	_trv__DeleteReceiverResponse trv__DeleteReceiverResponse;
	trv__DeleteReceiverResponse.soap_default(soap);
	soap_default___trv__DeleteReceiver(soap, &soap_tmp___trv__DeleteReceiver);
	if (!soap_get___trv__DeleteReceiver(soap, &soap_tmp___trv__DeleteReceiver, "-trv:DeleteReceiver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->DeleteReceiver(soap_tmp___trv__DeleteReceiver.trv__DeleteReceiver, trv__DeleteReceiverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__DeleteReceiverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__DeleteReceiverResponse.soap_put(soap, "trv:DeleteReceiverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__DeleteReceiverResponse.soap_put(soap, "trv:DeleteReceiverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__ConfigureReceiver(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__ConfigureReceiver soap_tmp___trv__ConfigureReceiver;
	_trv__ConfigureReceiverResponse trv__ConfigureReceiverResponse;
	trv__ConfigureReceiverResponse.soap_default(soap);
	soap_default___trv__ConfigureReceiver(soap, &soap_tmp___trv__ConfigureReceiver);
	if (!soap_get___trv__ConfigureReceiver(soap, &soap_tmp___trv__ConfigureReceiver, "-trv:ConfigureReceiver", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->ConfigureReceiver(soap_tmp___trv__ConfigureReceiver.trv__ConfigureReceiver, trv__ConfigureReceiverResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__ConfigureReceiverResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__ConfigureReceiverResponse.soap_put(soap, "trv:ConfigureReceiverResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__ConfigureReceiverResponse.soap_put(soap, "trv:ConfigureReceiverResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__SetReceiverMode(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__SetReceiverMode soap_tmp___trv__SetReceiverMode;
	_trv__SetReceiverModeResponse trv__SetReceiverModeResponse;
	trv__SetReceiverModeResponse.soap_default(soap);
	soap_default___trv__SetReceiverMode(soap, &soap_tmp___trv__SetReceiverMode);
	if (!soap_get___trv__SetReceiverMode(soap, &soap_tmp___trv__SetReceiverMode, "-trv:SetReceiverMode", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->SetReceiverMode(soap_tmp___trv__SetReceiverMode.trv__SetReceiverMode, trv__SetReceiverModeResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__SetReceiverModeResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__SetReceiverModeResponse.soap_put(soap, "trv:SetReceiverModeResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__SetReceiverModeResponse.soap_put(soap, "trv:SetReceiverModeResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___trv__GetReceiverState(struct soap *soap, ReceiverBindingService *service)
{	struct __trv__GetReceiverState soap_tmp___trv__GetReceiverState;
	_trv__GetReceiverStateResponse trv__GetReceiverStateResponse;
	trv__GetReceiverStateResponse.soap_default(soap);
	soap_default___trv__GetReceiverState(soap, &soap_tmp___trv__GetReceiverState);
	if (!soap_get___trv__GetReceiverState(soap, &soap_tmp___trv__GetReceiverState, "-trv:GetReceiverState", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetReceiverState(soap_tmp___trv__GetReceiverState.trv__GetReceiverState, trv__GetReceiverStateResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	trv__GetReceiverStateResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || trv__GetReceiverStateResponse.soap_put(soap, "trv:GetReceiverStateResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || trv__GetReceiverStateResponse.soap_put(soap, "trv:GetReceiverStateResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
