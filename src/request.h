//
// Created by licks on 24-7-2.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <memory>
#include <string>

template <class T>
struct SoapDeleterReq
{
    void operator()(T* p)
    {
        if (p) p->soap_del();
    }
};


template <class T, class Deleter = SoapDeleterReq<T>>
class Request final : public T
{
public:
    Request() :
        T(),
        soap_action_(),
        deleter_()
    {
    }

    virtual ~Request()
    {
        deleter_(this);
    }

    //! Use to overwrite the SOAP action of the request
    void SetSoapAction(const std::string& rAction) { soap_action_ = rAction; }
    //! The SOAP action to use. Returns a null string if the default SOAP action is used
    [[nodiscard]] std::string GetSoapAction() const { return soap_action_; }
    Request(const Request&) = delete;
    Request& operator=(const Request&) = delete;
private:
    std::string soap_action_{};
    Deleter deleter_;
};
#endif //REQUEST_H
