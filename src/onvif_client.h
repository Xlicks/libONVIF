//
// Created by licks on 24-7-1.
//

#ifndef ONVIF_CLIENT_H
#define ONVIF_CLIENT_H

#include <memory>
#include <string>

#include "global.h"
#include "soap_context.h"

struct soap;
struct ClientPrivate;

enum AuthMode { NO_AUTH, HTTP_DIGEST, WS_USERNAME_TOKEN, BOTH, AUTO };

class OnvifClient
{
public:
    /*
     * @brief 构造一个新的COnvifClient对象
     * @param endpoint 设备的端点地址
     * @param soap_ctx 可选的SOAP上下文对象，默认为std::make_shared<CSoapContext>()
     */
    explicit OnvifClient(const std::string& endpoint, std::shared_ptr<SoapContext> soap_ctx = std::make_shared<SoapContext>());
    virtual ~OnvifClient();
    void SetAuth(const std::string &user_name, const std::string &password, AuthMode mode = AUTO) const;
    void DisableAuth() const;
    [[nodiscard]] std::shared_ptr<SoapContext> GetContext() const;
    [[nodiscard]] std::string GetFaultString() const;
    [[nodiscard]] std::string GetFaultDetail() const;
    [[nodiscard]] std::string GetEndpoint() const;
    void SetEndpoint(const std::string& endpoint) const;
    void CancelRequest() const;
    DISALLOW_COPY_AND_ASSIGN(OnvifClient);
protected:
    [[nodiscard]] soap* AcquireContext() const;
    [[nodiscard]] soap* TryAcquireContext(int timeoutMs = 0) const;
    void ReleaseContext(soap* ctx) const;
    int ReTry(const soap* ctx) const;
private:
    ClientPrivate* impl_;
}; // class COnvifClient

#endif //ONVIF_CLIENT_H
