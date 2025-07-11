/* soapImagingBindingService.cpp
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

#include "soapImagingBindingService.h"

ImagingBindingService::ImagingBindingService()
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ImagingBindingService::ImagingBindingService(const ImagingBindingService& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
}

ImagingBindingService::ImagingBindingService(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	ImagingBindingService_init(_soap->imode, _soap->omode);
}

ImagingBindingService::ImagingBindingService(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingService_init(iomode, iomode);
}

ImagingBindingService::ImagingBindingService(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingService_init(imode, omode);
}

ImagingBindingService::~ImagingBindingService()
{	if (this->soap_own)
	{	ImagingBindingService::destroy();
		soap_free(this->soap);
	}
}

void ImagingBindingService::ImagingBindingService_init(soap_mode imode, soap_mode omode)
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

void ImagingBindingService::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void ImagingBindingService::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	ImagingBindingService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
ImagingBindingService *ImagingBindingService::copy()
{	ImagingBindingService *dup = SOAP_NEW_UNMANAGED(ImagingBindingService);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}
#endif

ImagingBindingService& ImagingBindingService::operator=(const ImagingBindingService& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
	}
	return *this;
}

int ImagingBindingService::soap_close_socket()
{	return soap_closesock(this->soap);
}

int ImagingBindingService::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

int ImagingBindingService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this->soap, string, detailXML);
}

int ImagingBindingService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

int ImagingBindingService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this->soap, string, detailXML);
}

int ImagingBindingService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

void ImagingBindingService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void ImagingBindingService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *ImagingBindingService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

void ImagingBindingService::soap_noheader()
{	this->soap->header = NULL;
}

void ImagingBindingService::soap_header(struct _wsse__Security *wsse__Security, char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance)
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

::SOAP_ENV__Header *ImagingBindingService::soap_header()
{	return this->soap->header;
}

#ifndef WITH_NOIO
int ImagingBindingService::run(int port, int backlog)
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
int ImagingBindingService::ssl_run(int port, int backlog)
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

SOAP_SOCKET ImagingBindingService::bind(const char *host, int port, int backlog)
{	return soap_bind(this->soap, host, port, backlog);
}

SOAP_SOCKET ImagingBindingService::accept()
{	return soap_accept(this->soap);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int ImagingBindingService::ssl_accept()
{	return soap_ssl_accept(this->soap);
}
#endif
#endif

int ImagingBindingService::serve()
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

static int serve___timg__GetServiceCapabilities(struct soap*, ImagingBindingService*);
static int serve___timg__GetImagingSettings(struct soap*, ImagingBindingService*);
static int serve___timg__SetImagingSettings(struct soap*, ImagingBindingService*);
static int serve___timg__GetOptions(struct soap*, ImagingBindingService*);
static int serve___timg__Move(struct soap*, ImagingBindingService*);
static int serve___timg__Stop(struct soap*, ImagingBindingService*);
static int serve___timg__GetStatus(struct soap*, ImagingBindingService*);
static int serve___timg__GetMoveOptions(struct soap*, ImagingBindingService*);
static int serve___timg__GetPresets(struct soap*, ImagingBindingService*);
static int serve___timg__GetCurrentPreset(struct soap*, ImagingBindingService*);
static int serve___timg__SetCurrentPreset(struct soap*, ImagingBindingService*);

int ImagingBindingService::dispatch()
{	return dispatch(this->soap);
}

int ImagingBindingService::dispatch(struct soap* soap)
{
	ImagingBindingService_init(soap->imode, soap->omode);
	if (soap->action)
	{
		const char *soap_action[] = { "http://www.onvif.org/ver20/imaging/wsdl/FocusStop", "http://www.onvif.org/ver20/imaging/wsdl/GetCurrentPreset", "http://www.onvif.org/ver20/imaging/wsdl/GetImagingSettings", "http://www.onvif.org/ver20/imaging/wsdl/GetMoveOptions", "http://www.onvif.org/ver20/imaging/wsdl/GetOptions", "http://www.onvif.org/ver20/imaging/wsdl/GetPresets", "http://www.onvif.org/ver20/imaging/wsdl/GetServiceCapabilities", "http://www.onvif.org/ver20/imaging/wsdl/GetStatus", "http://www.onvif.org/ver20/imaging/wsdl/Move", "http://www.onvif.org/ver20/imaging/wsdl/SetCurrentPreset", "http://www.onvif.org/ver20/imaging/wsdl/SetImagingSettings",  };
		switch (soap_binary_search_string(soap_action, 11, soap->action))
		{
			case 0:	
				return serve___timg__Stop(soap, this);
			case 1:	
				return serve___timg__GetCurrentPreset(soap, this);
			case 2:	
				return serve___timg__GetImagingSettings(soap, this);
			case 3:	
				return serve___timg__GetMoveOptions(soap, this);
			case 4:	
				return serve___timg__GetOptions(soap, this);
			case 5:	
				return serve___timg__GetPresets(soap, this);
			case 6:	
				return serve___timg__GetServiceCapabilities(soap, this);
			case 7:	
				return serve___timg__GetStatus(soap, this);
			case 8:	
				return serve___timg__Move(soap, this);
			case 9:	
				return serve___timg__SetCurrentPreset(soap, this);
			case 10:	
				return serve___timg__SetImagingSettings(soap, this);
		}
	}
	(void)soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "timg:GetServiceCapabilities"))
		return serve___timg__GetServiceCapabilities(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetImagingSettings"))
		return serve___timg__GetImagingSettings(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:SetImagingSettings"))
		return serve___timg__SetImagingSettings(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetOptions"))
		return serve___timg__GetOptions(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:Move"))
		return serve___timg__Move(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:Stop"))
		return serve___timg__Stop(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetStatus"))
		return serve___timg__GetStatus(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetMoveOptions"))
		return serve___timg__GetMoveOptions(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetPresets"))
		return serve___timg__GetPresets(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:GetCurrentPreset"))
		return serve___timg__GetCurrentPreset(soap, this);
	if (!soap_match_tag(soap, soap->tag, "timg:SetCurrentPreset"))
		return serve___timg__SetCurrentPreset(soap, this);
	return soap->error = SOAP_NO_METHOD;
}

static int serve___timg__GetServiceCapabilities(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetServiceCapabilities soap_tmp___timg__GetServiceCapabilities;
	_timg__GetServiceCapabilitiesResponse timg__GetServiceCapabilitiesResponse;
	timg__GetServiceCapabilitiesResponse.soap_default(soap);
	soap_default___timg__GetServiceCapabilities(soap, &soap_tmp___timg__GetServiceCapabilities);
	if (!soap_get___timg__GetServiceCapabilities(soap, &soap_tmp___timg__GetServiceCapabilities, "-timg:GetServiceCapabilities", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetServiceCapabilities(soap_tmp___timg__GetServiceCapabilities.timg__GetServiceCapabilities, timg__GetServiceCapabilitiesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetServiceCapabilitiesResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetServiceCapabilitiesResponse.soap_put(soap, "timg:GetServiceCapabilitiesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetServiceCapabilitiesResponse.soap_put(soap, "timg:GetServiceCapabilitiesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetImagingSettings(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetImagingSettings soap_tmp___timg__GetImagingSettings;
	_timg__GetImagingSettingsResponse timg__GetImagingSettingsResponse;
	timg__GetImagingSettingsResponse.soap_default(soap);
	soap_default___timg__GetImagingSettings(soap, &soap_tmp___timg__GetImagingSettings);
	if (!soap_get___timg__GetImagingSettings(soap, &soap_tmp___timg__GetImagingSettings, "-timg:GetImagingSettings", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetImagingSettings(soap_tmp___timg__GetImagingSettings.timg__GetImagingSettings, timg__GetImagingSettingsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetImagingSettingsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetImagingSettingsResponse.soap_put(soap, "timg:GetImagingSettingsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetImagingSettingsResponse.soap_put(soap, "timg:GetImagingSettingsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__SetImagingSettings(struct soap *soap, ImagingBindingService *service)
{	struct __timg__SetImagingSettings soap_tmp___timg__SetImagingSettings;
	_timg__SetImagingSettingsResponse timg__SetImagingSettingsResponse;
	timg__SetImagingSettingsResponse.soap_default(soap);
	soap_default___timg__SetImagingSettings(soap, &soap_tmp___timg__SetImagingSettings);
	if (!soap_get___timg__SetImagingSettings(soap, &soap_tmp___timg__SetImagingSettings, "-timg:SetImagingSettings", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->SetImagingSettings(soap_tmp___timg__SetImagingSettings.timg__SetImagingSettings, timg__SetImagingSettingsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__SetImagingSettingsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__SetImagingSettingsResponse.soap_put(soap, "timg:SetImagingSettingsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__SetImagingSettingsResponse.soap_put(soap, "timg:SetImagingSettingsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetOptions(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetOptions soap_tmp___timg__GetOptions;
	_timg__GetOptionsResponse timg__GetOptionsResponse;
	timg__GetOptionsResponse.soap_default(soap);
	soap_default___timg__GetOptions(soap, &soap_tmp___timg__GetOptions);
	if (!soap_get___timg__GetOptions(soap, &soap_tmp___timg__GetOptions, "-timg:GetOptions", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetOptions(soap_tmp___timg__GetOptions.timg__GetOptions, timg__GetOptionsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetOptionsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetOptionsResponse.soap_put(soap, "timg:GetOptionsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetOptionsResponse.soap_put(soap, "timg:GetOptionsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__Move(struct soap *soap, ImagingBindingService *service)
{	struct __timg__Move soap_tmp___timg__Move;
	_timg__MoveResponse timg__MoveResponse;
	timg__MoveResponse.soap_default(soap);
	soap_default___timg__Move(soap, &soap_tmp___timg__Move);
	if (!soap_get___timg__Move(soap, &soap_tmp___timg__Move, "-timg:Move", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Move(soap_tmp___timg__Move.timg__Move, timg__MoveResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__MoveResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__MoveResponse.soap_put(soap, "timg:MoveResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__MoveResponse.soap_put(soap, "timg:MoveResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__Stop(struct soap *soap, ImagingBindingService *service)
{	struct __timg__Stop soap_tmp___timg__Stop;
	_timg__StopResponse timg__StopResponse;
	timg__StopResponse.soap_default(soap);
	soap_default___timg__Stop(soap, &soap_tmp___timg__Stop);
	if (!soap_get___timg__Stop(soap, &soap_tmp___timg__Stop, "-timg:Stop", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Stop(soap_tmp___timg__Stop.timg__Stop, timg__StopResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__StopResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__StopResponse.soap_put(soap, "timg:StopResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__StopResponse.soap_put(soap, "timg:StopResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetStatus(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetStatus soap_tmp___timg__GetStatus;
	_timg__GetStatusResponse timg__GetStatusResponse;
	timg__GetStatusResponse.soap_default(soap);
	soap_default___timg__GetStatus(soap, &soap_tmp___timg__GetStatus);
	if (!soap_get___timg__GetStatus(soap, &soap_tmp___timg__GetStatus, "-timg:GetStatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetStatus(soap_tmp___timg__GetStatus.timg__GetStatus, timg__GetStatusResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetStatusResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetStatusResponse.soap_put(soap, "timg:GetStatusResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetStatusResponse.soap_put(soap, "timg:GetStatusResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetMoveOptions(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetMoveOptions soap_tmp___timg__GetMoveOptions;
	_timg__GetMoveOptionsResponse timg__GetMoveOptionsResponse;
	timg__GetMoveOptionsResponse.soap_default(soap);
	soap_default___timg__GetMoveOptions(soap, &soap_tmp___timg__GetMoveOptions);
	if (!soap_get___timg__GetMoveOptions(soap, &soap_tmp___timg__GetMoveOptions, "-timg:GetMoveOptions", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetMoveOptions(soap_tmp___timg__GetMoveOptions.timg__GetMoveOptions, timg__GetMoveOptionsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetMoveOptionsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetMoveOptionsResponse.soap_put(soap, "timg:GetMoveOptionsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetMoveOptionsResponse.soap_put(soap, "timg:GetMoveOptionsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetPresets(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetPresets soap_tmp___timg__GetPresets;
	_timg__GetPresetsResponse timg__GetPresetsResponse;
	timg__GetPresetsResponse.soap_default(soap);
	soap_default___timg__GetPresets(soap, &soap_tmp___timg__GetPresets);
	if (!soap_get___timg__GetPresets(soap, &soap_tmp___timg__GetPresets, "-timg:GetPresets", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetPresets(soap_tmp___timg__GetPresets.timg__GetPresets, timg__GetPresetsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetPresetsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetPresetsResponse.soap_put(soap, "timg:GetPresetsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetPresetsResponse.soap_put(soap, "timg:GetPresetsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__GetCurrentPreset(struct soap *soap, ImagingBindingService *service)
{	struct __timg__GetCurrentPreset soap_tmp___timg__GetCurrentPreset;
	_timg__GetCurrentPresetResponse timg__GetCurrentPresetResponse;
	timg__GetCurrentPresetResponse.soap_default(soap);
	soap_default___timg__GetCurrentPreset(soap, &soap_tmp___timg__GetCurrentPreset);
	if (!soap_get___timg__GetCurrentPreset(soap, &soap_tmp___timg__GetCurrentPreset, "-timg:GetCurrentPreset", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->GetCurrentPreset(soap_tmp___timg__GetCurrentPreset.timg__GetCurrentPreset, timg__GetCurrentPresetResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__GetCurrentPresetResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__GetCurrentPresetResponse.soap_put(soap, "timg:GetCurrentPresetResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__GetCurrentPresetResponse.soap_put(soap, "timg:GetCurrentPresetResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___timg__SetCurrentPreset(struct soap *soap, ImagingBindingService *service)
{	struct __timg__SetCurrentPreset soap_tmp___timg__SetCurrentPreset;
	_timg__SetCurrentPresetResponse timg__SetCurrentPresetResponse;
	timg__SetCurrentPresetResponse.soap_default(soap);
	soap_default___timg__SetCurrentPreset(soap, &soap_tmp___timg__SetCurrentPreset);
	if (!soap_get___timg__SetCurrentPreset(soap, &soap_tmp___timg__SetCurrentPreset, "-timg:SetCurrentPreset", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->SetCurrentPreset(soap_tmp___timg__SetCurrentPreset.timg__SetCurrentPreset, timg__SetCurrentPresetResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	timg__SetCurrentPresetResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || timg__SetCurrentPresetResponse.soap_put(soap, "timg:SetCurrentPresetResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || timg__SetCurrentPresetResponse.soap_put(soap, "timg:SetCurrentPresetResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
