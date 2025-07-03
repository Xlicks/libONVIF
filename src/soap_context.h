//
// Created by licks on 24-7-1.
//

#ifndef SOAP_CONTEXT_H
#define SOAP_CONTEXT_H

#include "soapH.h"
#include "soap_auth_handler.h"


#define SOAP_NEW_IO_DEFAULT (SOAP_IO_DEFAULT | SOAP_C_UTFSTRING | SOAP_DOM_NODE | SOAP_XML_TREE)
#define SOAP_NEW_SSL_DEFAULT (SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION | SOAP_TLSv1 | SOAP_SSL_CLIENT)
#define SOAP_DEFAULT_CONNECT_TIMEOUT 10000
#define SOAP_DEFAULT_RECEIVE_TIMEOUT 10000
#define SOAP_DEFAULT_SEND_TIMEOUT 10000

struct Namespace;
struct CtxPrivate;
class SoapAuthHandler;

class SoapContext
{
public:
    SoapContext();
    SoapContext(soap_mode imode, soap_mode omode);
    ~SoapContext();
    void SetIMode(soap_mode imode) const;
    void SetOMode(soap_mode omode) const;
    void EnableIModeFlags(soap_mode imode) const;
    void EnableModeFlags(soap_mode mode) const;
    void EnableOModeFlags(soap_mode omode) const;
    void DisableIModeFlags(soap_mode imode) const;
    void DisableModeFlags(soap_mode mode) const;
    void DisableOModeFlags(soap_mode omode) const;
    void EnablePrintRawSoap() const;
    void DisablePrintRawSoap() const;
    [[nodiscard]] std::string GetFaultString() const;
    [[nodiscard]] std::string GetFaultDetail() const;
    [[nodiscard]] int GetFaultCode() const;
    [[nodiscard]] std::string GetFaultSubCode() const;
#ifdef WITH_OPENSSL
    bool EnableSSL() const;
#endif
    void SoapDelete(void* p) const;
    void SoapDealloc(void* p) const;
    void SoapUnlink(const void* p) const;
    void SoapFreeTemp() const;
    void SetConnectTimeout(int timeoutMs) const;
    void SetSendTimeout(int timeoutMs) const;
    void SetReceiveTimeout(int timeoutMs) const;
    void SetSocketFlags(int soFlags) const; // soap::socket_flags
    void SetConnectFlags(int conFlags) const; // soap::connect_flags
    void SetBindFlags(int bindFlags) const; // soap::bind_flags
    void SetAcceptFlags(int acceptFlags) const; // soap::accept_flags
    static void ForceSocketClose();
    void Save() const;
    void Restore() const;
    [[nodiscard]] soap* Acquire() const;
    [[nodiscard]] soap* TryAcquire(int timeoutMs = 0) const;
    void Release() const;
    static const Namespace* GetDefaultNamespaces();
    static std::string GetPrefix(const std::string& ns);
    static std::string GetNamespace(const std::string& prefix);
    void SetSoapAuthHandler(std::unique_ptr<SoapAuthHandler> handler) const;
    void SetAuth(const std::string& user_name, const std::string& password,
                 AuthHandlerMode mode = AuthHandlerMode::AUTO) const;
    void DisableAuth() const;
    [[nodiscard]] bool IsAuthFault() const;
    static void Unauthorized();

    class Builder
    {
    public:
        Builder() : soap_context_(std::make_shared<SoapContext>())
        {
        }

        Builder& setConnectTimeout(const int timeoutMs)
        {
            soap_context_->SetConnectTimeout(timeoutMs);
            return *this;
        }

        Builder& setSendTimeout(const int timeoutMs)
        {
            soap_context_->SetSendTimeout(timeoutMs);
            return *this;
        }

        Builder& setReceiveTimeout(const int timeoutMs)
        {
            soap_context_->SetReceiveTimeout(timeoutMs);
            return *this;
        }

        Builder& enableIMode(const soap_mode timeoutMs)
        {
            soap_context_->EnableIModeFlags(timeoutMs);
            return *this;
        }

        Builder& enableOMode(const soap_mode timeoutMs)
        {
            soap_context_->EnableOModeFlags(timeoutMs);
            return *this;
        }

        Builder& enablePrintRawSoap()
        {
            soap_context_->EnablePrintRawSoap();
            return *this;
        }

        Builder& SetSoapAuthHandler(std::unique_ptr<SoapAuthHandler> handler)
        {
            soap_context_->SetSoapAuthHandler(std::move(handler));
            return *this;
        }

#ifdef WITH_OPENSSL
        Builder &EnableSSL()
        {
            soap_context_->EnableSSL();
            return *this;
        }
#endif // WITH_OPENSSL

        [[nodiscard]] const std::shared_ptr<SoapContext>& Build() const { return soap_context_; }

    private:
        std::shared_ptr<SoapContext> soap_context_;
    };
    //禁止拷贝构造函数和赋值运算符
    SoapContext(const SoapContext&) = delete;
    SoapContext& operator=(const SoapContext&) = delete;
private:
    void InitCtx() const;
    friend class OnvifClient;
    void RestoreAuthData() const;
    [[nodiscard]] bool ProcessAuthFaultAndRetry() const;
    CtxPrivate* context_impl_;
}; // class SoapContext
#endif //SOAP_CONTEXT_H
