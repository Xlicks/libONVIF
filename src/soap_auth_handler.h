//
// Created by licks on 24-7-1.
//

#ifndef SOAP_AUTH_HANDLER_H
#define SOAP_AUTH_HANDLER_H
#include <string>

struct soap;
struct DefaultAuthHandlerPrivate;

enum class AuthHandlerMode { NO_AUTH = 0, HTTP_DIGEST = 1, WS_USERNAME_TOKEN = 2, BOTH = 3, AUTO = 4, CUSTOM = 100 };

class SoapAuthHandler
{
public:
    virtual ~SoapAuthHandler() = default;
    virtual void SetAuth(soap* ctx, const std::string& user_name, const std::string& password,
                         AuthHandlerMode mode) = 0;
    virtual void FreeAuth(soap* ctx) = 0;
    virtual bool IsAuthFault(soap* ctx) = 0;
    virtual void RestoreAuthData(soap* ctx) = 0;
    virtual bool ProcessAuthFaultAndRetry(soap* ctx, int num_retry) = 0;

    virtual void ProcessResponse(soap* ctx)
    {
    };
    void Unauthorized();
};

class DefaultAuthHandler final : public SoapAuthHandler
{
public:
    DefaultAuthHandler();
    ~DefaultAuthHandler() override;
    void SetAuth(soap* ctx, const std::string& user_name, const std::string& password, AuthHandlerMode mode) override;
    void FreeAuth(soap* ctx) override;
    bool IsAuthFault(soap* ctx) override;
    static bool isHttpAuthFault(const soap* ctx);
    static bool isWssTokenAuthFault(soap* ctx);
    void RestoreAuthData(soap* ctx) override;
    bool ProcessAuthFaultAndRetry(soap* ctx, int num_retry) override;

private:
    DefaultAuthHandlerPrivate* auth_handler_impl_;
};

#endif //SOAP_AUTH_HANDLER_H
