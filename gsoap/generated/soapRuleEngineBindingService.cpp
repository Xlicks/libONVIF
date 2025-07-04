/* soapRuleEngineBindingService.cpp
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

#include "soapRuleEngineBindingService.h"

RuleEngineBindingService::RuleEngineBindingService()
{	this->soap = soap_new();
	this->soap_own = true;
	RuleEngineBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

RuleEngineBindingService::RuleEngineBindingService(const RuleEngineBindingService& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
}

RuleEngineBindingService::RuleEngineBindingService(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	RuleEngineBindingService_init(_soap->imode, _soap->omode);
}

RuleEngineBindingService::RuleEngineBindingService(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	RuleEngineBindingService_init(iomode, iomode);
}

RuleEngineBindingService::RuleEngineBindingService(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	RuleEngineBindingService_init(imode, omode);
}

RuleEngineBindingService::~RuleEngineBindingService()
{	if (this->soap_own)
	{	RuleEngineBindingService::destroy();
		soap_free(this->soap);
	}
}

void RuleEngineBindingService::RuleEngineBindingService_init(soap_mode imode, soap_mode omode)
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

void RuleEngineBindingService::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void RuleEngineBindingService::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	RuleEngineBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
RuleEngineBindingService *RuleEngineBindingService::copy()
{	RuleEngineBindingService *dup = SOAP_NEW_UNMANAGED(RuleEngineBindingService);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}
#endif

RuleEngineBindingService& RuleEngineBindingService::operator=(const RuleEngineBindingService& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
	}
	return *this;
}

int RuleEngineBindingService::soap_close_socket()
{	return soap_closesock(this->soap);
}

int RuleEngineBindingService::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

int RuleEngineBindingService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this->soap, string, detailXML);
}

int RuleEngineBindingService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

int RuleEngineBindingService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this->soap, string, detailXML);
}

int RuleEngineBindingService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

void RuleEngineBindingService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void RuleEngineBindingService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *RuleEngineBindingService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

void RuleEngineBindingService::soap_noheader()
{	this->soap->header = NULL;
}

void RuleEngineBindingService::soap_header(struct _wsse__Security *wsse__Security, char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance)
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

::SOAP_ENV__Header *RuleEngineBindingService::soap_header()
{	return this->soap->header;
}

#ifndef WITH_NOIO
int RuleEngineBindingService::run(int port, int backlog)
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
int RuleEngineBindingService::ssl_run(int port, int backlog)
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

SOAP_SOCKET RuleEngineBindingService::bind(const char *host, int port, int backlog)
{	return soap_bind(this->soap, host, port, backlog);
}

SOAP_SOCKET RuleEngineBindingService::accept()
{	return soap_accept(this->soap);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int RuleEngineBindingService::ssl_accept()
{	return soap_ssl_accept(this->soap);
}
#endif
#endif

int RuleEngineBindingService::serve()
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

static int serve___tan__GetSupportedRules(struct soap*, RuleEngineBindingService*);
static int serve___tan__CreateRules(struct soap*, RuleEngineBindingService*);
static int serve___tan__DeleteRules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetRules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetRuleOptions(struct soap*, RuleEngineBindingService*);
static int serve___tan__ModifyRules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetServiceCapabilities(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetSupportedAnalyticsModules(struct soap*, RuleEngineBindingService*);
static int serve___tan__CreateAnalyticsModules(struct soap*, RuleEngineBindingService*);
static int serve___tan__DeleteAnalyticsModules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetAnalyticsModules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetAnalyticsModuleOptions(struct soap*, RuleEngineBindingService*);
static int serve___tan__ModifyAnalyticsModules(struct soap*, RuleEngineBindingService*);
static int serve___tan__GetSupportedMetadata(struct soap*, RuleEngineBindingService*);

int RuleEngineBindingService::dispatch()
{	return dispatch(this->soap);
}

int RuleEngineBindingService::dispatch(struct soap* soap)
{
	RuleEngineBindingService_init(soap->imode, soap->omode);
	if (soap->action)
	{
		const char *soap_action[] = { "http://www.onvif.org/ver20/analytics/wsdl/CreateAnalyticsModules", "http://www.onvif.org/ver20/analytics/wsdl/CreateRules", "http://www.onvif.org/ver20/analytics/wsdl/DeleteAnalyticsModules", "http://www.onvif.org/ver20/analytics/wsdl/DeleteRules", "http://www.onvif.org/ver20/analytics/wsdl/GetAnalyticsModuleOptions", "http://www.onvif.org/ver20/analytics/wsdl/GetAnalyticsModules", "http://www.onvif.org/ver20/analytics/wsdl/GetRuleOptions", "http://www.onvif.org/ver20/analytics/wsdl/GetRules", "http://www.onvif.org/ver20/analytics/wsdl/GetServiceCapabilities", "http://www.onvif.org/ver20/analytics/wsdl/GetSupportedAnalyticsModules", "http://www.onvif.org/ver20/analytics/wsdl/GetSupportedMetadata", "http://www.onvif.org/ver20/analytics/wsdl/GetSupportedRules", "http://www.onvif.org/ver20/analytics/wsdl/ModifyAnalyticsModules", "http://www.onvif.org/ver20/analytics/wsdl/ModifyRules",  };
		switch (soap_binary_search_string(soap_action, 14, soap->action))
		{
			case 0:	
				return serve___tan__CreateAnalyticsModules(soap, this);
			case 1:	
				return serve___tan__CreateRules(soap, this);
			case 2:	
				return serve___tan__DeleteAnalyticsModules(soap, this);
			case 3:	
				return serve___tan__DeleteRules(soap, this);
			case 4:	
				return serve___tan__GetAnalyticsModuleOptions(soap, this);
			case 5:	
				return serve___tan__GetAnalyticsModules(soap, this);
			case 6:	
				return serve___tan__GetRuleOptions(soap, this);
			case 7:	
				return serve___tan__GetRules(soap, this);
			case 8:	
				return serve___tan__GetServiceCapabilities(soap, this);
			case 9:	
				return serve___tan__GetSupportedAnalyticsModules(soap, this);
			case 10:	
				return serve___tan__GetSupportedMetadata(soap, this);
			case 11:	
				return serve___tan__GetSupportedRules(soap, this);
			case 12:	
				return serve___tan__ModifyAnalyticsModules(soap, this);
			case 13:	
				return serve___tan__ModifyRules(soap, this);
		}
	}
	(void)soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "tan:GetSupportedRules"))
		return serve___tan__GetSupportedRules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:CreateRules"))
		return serve___tan__CreateRules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:DeleteRules"))
		return serve___tan__DeleteRules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetRules"))
		return serve___tan__GetRules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetRuleOptions"))
		return serve___tan__GetRuleOptions(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:ModifyRules"))
		return serve___tan__ModifyRules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetServiceCapabilities"))
		return serve___tan__GetServiceCapabilities(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetSupportedAnalyticsModules"))
		return serve___tan__GetSupportedAnalyticsModules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:CreateAnalyticsModules"))
		return serve___tan__CreateAnalyticsModules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:DeleteAnalyticsModules"))
		return serve___tan__DeleteAnalyticsModules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetAnalyticsModules"))
		return serve___tan__GetAnalyticsModules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetAnalyticsModuleOptions"))
		return serve___tan__GetAnalyticsModuleOptions(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:ModifyAnalyticsModules"))
		return serve___tan__ModifyAnalyticsModules(soap, this);
	if (!soap_match_tag(soap, soap->tag, "tan:GetSupportedMetadata"))
		return serve___tan__GetSupportedMetadata(soap, this);
	return soap->error = SOAP_NO_METHOD;
}

static int serve___tan__GetSupportedRules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetSupportedRules soap_tmp___tan__GetSupportedRules;
	_tan__GetSupportedRulesResponse tan__GetSupportedRulesResponse;
	tan__GetSupportedRulesResponse.soap_default(soap);
	soap_default___tan__GetSupportedRules(soap, &soap_tmp___tan__GetSupportedRules);
	if (!soap_get___tan__GetSupportedRules(soap, &soap_tmp___tan__GetSupportedRules, "-tan:GetSupportedRules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetSupportedRules(soap_tmp___tan__GetSupportedRules.tan__GetSupportedRules, tan__GetSupportedRulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetSupportedRulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetSupportedRulesResponse.soap_put(soap, "tan:GetSupportedRulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetSupportedRulesResponse.soap_put(soap, "tan:GetSupportedRulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__CreateRules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__CreateRules soap_tmp___tan__CreateRules;
	_tan__CreateRulesResponse tan__CreateRulesResponse;
	tan__CreateRulesResponse.soap_default(soap);
	soap_default___tan__CreateRules(soap, &soap_tmp___tan__CreateRules);
	if (!soap_get___tan__CreateRules(soap, &soap_tmp___tan__CreateRules, "-tan:CreateRules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->CreateRules(soap_tmp___tan__CreateRules.tan__CreateRules, tan__CreateRulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__CreateRulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__CreateRulesResponse.soap_put(soap, "tan:CreateRulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__CreateRulesResponse.soap_put(soap, "tan:CreateRulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__DeleteRules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__DeleteRules soap_tmp___tan__DeleteRules;
	_tan__DeleteRulesResponse tan__DeleteRulesResponse;
	tan__DeleteRulesResponse.soap_default(soap);
	soap_default___tan__DeleteRules(soap, &soap_tmp___tan__DeleteRules);
	if (!soap_get___tan__DeleteRules(soap, &soap_tmp___tan__DeleteRules, "-tan:DeleteRules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->DeleteRules(soap_tmp___tan__DeleteRules.tan__DeleteRules, tan__DeleteRulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__DeleteRulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__DeleteRulesResponse.soap_put(soap, "tan:DeleteRulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__DeleteRulesResponse.soap_put(soap, "tan:DeleteRulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetRules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetRules soap_tmp___tan__GetRules;
	_tan__GetRulesResponse tan__GetRulesResponse;
	tan__GetRulesResponse.soap_default(soap);
	soap_default___tan__GetRules(soap, &soap_tmp___tan__GetRules);
	if (!soap_get___tan__GetRules(soap, &soap_tmp___tan__GetRules, "-tan:GetRules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetRules(soap_tmp___tan__GetRules.tan__GetRules, tan__GetRulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetRulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetRulesResponse.soap_put(soap, "tan:GetRulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetRulesResponse.soap_put(soap, "tan:GetRulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetRuleOptions(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetRuleOptions soap_tmp___tan__GetRuleOptions;
	_tan__GetRuleOptionsResponse tan__GetRuleOptionsResponse;
	tan__GetRuleOptionsResponse.soap_default(soap);
	soap_default___tan__GetRuleOptions(soap, &soap_tmp___tan__GetRuleOptions);
	if (!soap_get___tan__GetRuleOptions(soap, &soap_tmp___tan__GetRuleOptions, "-tan:GetRuleOptions", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetRuleOptions(soap_tmp___tan__GetRuleOptions.tan__GetRuleOptions, tan__GetRuleOptionsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetRuleOptionsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetRuleOptionsResponse.soap_put(soap, "tan:GetRuleOptionsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetRuleOptionsResponse.soap_put(soap, "tan:GetRuleOptionsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__ModifyRules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__ModifyRules soap_tmp___tan__ModifyRules;
	_tan__ModifyRulesResponse tan__ModifyRulesResponse;
	tan__ModifyRulesResponse.soap_default(soap);
	soap_default___tan__ModifyRules(soap, &soap_tmp___tan__ModifyRules);
	if (!soap_get___tan__ModifyRules(soap, &soap_tmp___tan__ModifyRules, "-tan:ModifyRules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->ModifyRules(soap_tmp___tan__ModifyRules.tan__ModifyRules, tan__ModifyRulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__ModifyRulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__ModifyRulesResponse.soap_put(soap, "tan:ModifyRulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__ModifyRulesResponse.soap_put(soap, "tan:ModifyRulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetServiceCapabilities(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetServiceCapabilities soap_tmp___tan__GetServiceCapabilities;
	_tan__GetServiceCapabilitiesResponse tan__GetServiceCapabilitiesResponse;
	tan__GetServiceCapabilitiesResponse.soap_default(soap);
	soap_default___tan__GetServiceCapabilities(soap, &soap_tmp___tan__GetServiceCapabilities);
	if (!soap_get___tan__GetServiceCapabilities(soap, &soap_tmp___tan__GetServiceCapabilities, "-tan:GetServiceCapabilities", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetServiceCapabilities(soap_tmp___tan__GetServiceCapabilities.tan__GetServiceCapabilities, tan__GetServiceCapabilitiesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetServiceCapabilitiesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetServiceCapabilitiesResponse.soap_put(soap, "tan:GetServiceCapabilitiesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetServiceCapabilitiesResponse.soap_put(soap, "tan:GetServiceCapabilitiesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetSupportedAnalyticsModules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetSupportedAnalyticsModules soap_tmp___tan__GetSupportedAnalyticsModules;
	_tan__GetSupportedAnalyticsModulesResponse tan__GetSupportedAnalyticsModulesResponse;
	tan__GetSupportedAnalyticsModulesResponse.soap_default(soap);
	soap_default___tan__GetSupportedAnalyticsModules(soap, &soap_tmp___tan__GetSupportedAnalyticsModules);
	if (!soap_get___tan__GetSupportedAnalyticsModules(soap, &soap_tmp___tan__GetSupportedAnalyticsModules, "-tan:GetSupportedAnalyticsModules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetSupportedAnalyticsModules(soap_tmp___tan__GetSupportedAnalyticsModules.tan__GetSupportedAnalyticsModules, tan__GetSupportedAnalyticsModulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetSupportedAnalyticsModulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetSupportedAnalyticsModulesResponse.soap_put(soap, "tan:GetSupportedAnalyticsModulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetSupportedAnalyticsModulesResponse.soap_put(soap, "tan:GetSupportedAnalyticsModulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__CreateAnalyticsModules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__CreateAnalyticsModules soap_tmp___tan__CreateAnalyticsModules;
	_tan__CreateAnalyticsModulesResponse tan__CreateAnalyticsModulesResponse;
	tan__CreateAnalyticsModulesResponse.soap_default(soap);
	soap_default___tan__CreateAnalyticsModules(soap, &soap_tmp___tan__CreateAnalyticsModules);
	if (!soap_get___tan__CreateAnalyticsModules(soap, &soap_tmp___tan__CreateAnalyticsModules, "-tan:CreateAnalyticsModules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->CreateAnalyticsModules(soap_tmp___tan__CreateAnalyticsModules.tan__CreateAnalyticsModules, tan__CreateAnalyticsModulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__CreateAnalyticsModulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__CreateAnalyticsModulesResponse.soap_put(soap, "tan:CreateAnalyticsModulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__CreateAnalyticsModulesResponse.soap_put(soap, "tan:CreateAnalyticsModulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__DeleteAnalyticsModules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__DeleteAnalyticsModules soap_tmp___tan__DeleteAnalyticsModules;
	_tan__DeleteAnalyticsModulesResponse tan__DeleteAnalyticsModulesResponse;
	tan__DeleteAnalyticsModulesResponse.soap_default(soap);
	soap_default___tan__DeleteAnalyticsModules(soap, &soap_tmp___tan__DeleteAnalyticsModules);
	if (!soap_get___tan__DeleteAnalyticsModules(soap, &soap_tmp___tan__DeleteAnalyticsModules, "-tan:DeleteAnalyticsModules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->DeleteAnalyticsModules(soap_tmp___tan__DeleteAnalyticsModules.tan__DeleteAnalyticsModules, tan__DeleteAnalyticsModulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__DeleteAnalyticsModulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__DeleteAnalyticsModulesResponse.soap_put(soap, "tan:DeleteAnalyticsModulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__DeleteAnalyticsModulesResponse.soap_put(soap, "tan:DeleteAnalyticsModulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetAnalyticsModules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetAnalyticsModules soap_tmp___tan__GetAnalyticsModules;
	_tan__GetAnalyticsModulesResponse tan__GetAnalyticsModulesResponse;
	tan__GetAnalyticsModulesResponse.soap_default(soap);
	soap_default___tan__GetAnalyticsModules(soap, &soap_tmp___tan__GetAnalyticsModules);
	if (!soap_get___tan__GetAnalyticsModules(soap, &soap_tmp___tan__GetAnalyticsModules, "-tan:GetAnalyticsModules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetAnalyticsModules(soap_tmp___tan__GetAnalyticsModules.tan__GetAnalyticsModules, tan__GetAnalyticsModulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetAnalyticsModulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetAnalyticsModulesResponse.soap_put(soap, "tan:GetAnalyticsModulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetAnalyticsModulesResponse.soap_put(soap, "tan:GetAnalyticsModulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetAnalyticsModuleOptions(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetAnalyticsModuleOptions soap_tmp___tan__GetAnalyticsModuleOptions;
	_tan__GetAnalyticsModuleOptionsResponse tan__GetAnalyticsModuleOptionsResponse;
	tan__GetAnalyticsModuleOptionsResponse.soap_default(soap);
	soap_default___tan__GetAnalyticsModuleOptions(soap, &soap_tmp___tan__GetAnalyticsModuleOptions);
	if (!soap_get___tan__GetAnalyticsModuleOptions(soap, &soap_tmp___tan__GetAnalyticsModuleOptions, "-tan:GetAnalyticsModuleOptions", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetAnalyticsModuleOptions(soap_tmp___tan__GetAnalyticsModuleOptions.tan__GetAnalyticsModuleOptions, tan__GetAnalyticsModuleOptionsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetAnalyticsModuleOptionsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetAnalyticsModuleOptionsResponse.soap_put(soap, "tan:GetAnalyticsModuleOptionsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetAnalyticsModuleOptionsResponse.soap_put(soap, "tan:GetAnalyticsModuleOptionsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__ModifyAnalyticsModules(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__ModifyAnalyticsModules soap_tmp___tan__ModifyAnalyticsModules;
	_tan__ModifyAnalyticsModulesResponse tan__ModifyAnalyticsModulesResponse;
	tan__ModifyAnalyticsModulesResponse.soap_default(soap);
	soap_default___tan__ModifyAnalyticsModules(soap, &soap_tmp___tan__ModifyAnalyticsModules);
	if (!soap_get___tan__ModifyAnalyticsModules(soap, &soap_tmp___tan__ModifyAnalyticsModules, "-tan:ModifyAnalyticsModules", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->ModifyAnalyticsModules(soap_tmp___tan__ModifyAnalyticsModules.tan__ModifyAnalyticsModules, tan__ModifyAnalyticsModulesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__ModifyAnalyticsModulesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__ModifyAnalyticsModulesResponse.soap_put(soap, "tan:ModifyAnalyticsModulesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__ModifyAnalyticsModulesResponse.soap_put(soap, "tan:ModifyAnalyticsModulesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tan__GetSupportedMetadata(struct soap *soap, RuleEngineBindingService *service)
{	struct __tan__GetSupportedMetadata soap_tmp___tan__GetSupportedMetadata;
	_tan__GetSupportedMetadataResponse tan__GetSupportedMetadataResponse;
	tan__GetSupportedMetadataResponse.soap_default(soap);
	soap_default___tan__GetSupportedMetadata(soap, &soap_tmp___tan__GetSupportedMetadata);
	if (!soap_get___tan__GetSupportedMetadata(soap, &soap_tmp___tan__GetSupportedMetadata, "-tan:GetSupportedMetadata", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetSupportedMetadata(soap_tmp___tan__GetSupportedMetadata.tan__GetSupportedMetadata, tan__GetSupportedMetadataResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	tan__GetSupportedMetadataResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || tan__GetSupportedMetadataResponse.soap_put(soap, "tan:GetSupportedMetadataResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || tan__GetSupportedMetadataResponse.soap_put(soap, "tan:GetSupportedMetadataResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
