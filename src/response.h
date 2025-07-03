//
// Created by licks on 24-7-2.
//

#ifndef RESPONSE_H
#define RESPONSE_H
#include "soap_context.h"
#include "soapH.h"
#include <string>
#include <utility>


#define GENERIC_FAULT 600

template <class T>
struct SoapDeleter
{
    void operator()(T* p)
    {
        if (p) p->soap_del();
        delete p;
    }
};

//! Duplicator functor
template <class T>
struct SoapDuplicator
{
    T* operator()(const T* p) { return p->soap_dup(); }
};

class SimpleResponse
{
public:
    SimpleResponse() : error_code_(SOAP_OK), fault_(), fault_detail_(), fault_subcode_(), is_auth_fault_(false)
    {
    }

    explicit SimpleResponse(const int errorCode, std::string  rFault = std::string(), std::string  rFaultDetail = std::string()) :
        error_code_(errorCode), fault_(std::move(rFault)), fault_detail_(std::move(rFaultDetail)), fault_subcode_(), is_auth_fault_(false)
    {
    }

    virtual ~SimpleResponse() = default;

    SimpleResponse(const SimpleResponse& other) = default;

    SimpleResponse& operator=(const SimpleResponse& other)
    {
        if (&other == this)
        {
            return *this;
        }
        this->error_code_ = other.error_code_;
        this->fault_ = other.fault_;
        this->fault_detail_ = other.fault_detail_;
        this->fault_subcode_ = other.fault_subcode_;
        this->is_auth_fault_ = other.is_auth_fault_;
        return *this;
    }

    [[nodiscard]] std::string getSoapFault() const { return fault_; }
    void setFault(const std::string& rFault) { fault_ = rFault; }
    [[nodiscard]] std::string getSoapFaultDetail() const { return fault_detail_; }
    void setFaultDetail(const std::string& rFaultDetail) { fault_detail_ = rFaultDetail; }
    [[nodiscard]] std::string getCompleteFault() const
    {
        auto whatFault = std::string("No Fault");
        if (isFault())
        {
            if (isTcpFault())
                whatFault = "TCP Fault: ";
            else if (isSoapFault())
                whatFault = "SOAP Fault: ";
            else if (isXmlValidationFault())
                whatFault = "XML Val Fault: ";
            else if (isSslFault())
                whatFault = "SSL Fault: ";
            else if (isZlibFault())
                whatFault = "Zlib Fault: ";
            else if (isHttpFault())
                whatFault = "HTTP Fault: ";
            else
                whatFault = "Generic Fault: ";
            if (isAuthFault())
            {
                whatFault += "(Authentication failed) " + whatFault;
            }
            whatFault += getSoapFault();
            whatFault += getSoapFaultDetail();
        }
        return whatFault;
    }
    [[nodiscard]] int getErrorCode() const { return error_code_; }
    void setErrorCode(const int errorCode) { error_code_ = errorCode; }
    [[nodiscard]] std::string getFaultSubcode() const { return fault_subcode_; }
    void setFaultSubcode(const std::string& rFaultSubcode) { fault_subcode_ = rFaultSubcode; }
    [[nodiscard]] virtual bool isSuccess() const { return !isFault(); }
    [[nodiscard]] virtual bool isFault() const { return error_code_ != SOAP_OK; }
    [[nodiscard]] bool isTcpFault() const { return soap_tcp_error_check(error_code_); }
    [[nodiscard]] bool isSoapFault() const { return soap_soap_error_check(error_code_); }
    [[nodiscard]] bool isXmlValidationFault() const { return soap_xml_error_check(error_code_); }
    [[nodiscard]] bool isSslFault() const { return soap_ssl_error_check(error_code_); }
    [[nodiscard]] bool isZlibFault() const { return soap_zlib_error_check(error_code_); }
    [[nodiscard]] bool isHttpFault() const { return soap_http_error_check(error_code_); }
    [[nodiscard]] bool isAuthFault() const { return is_auth_fault_; }
    explicit operator bool() const { return isSuccess(); }

    virtual void populateFromCtx(const std::shared_ptr<SoapContext>& soap_ctx)
    {
        if (const auto errorCode = soap_ctx->GetFaultCode(); errorCode != SOAP_OK)
        {
            setErrorCode(errorCode);
            setFault(soap_ctx->GetFaultString());
            setFaultDetail(soap_ctx->GetFaultDetail());
            setFaultSubcode(soap_ctx->GetFaultSubCode());
            is_auth_fault_ = soap_ctx->IsAuthFault();
        }
        else
        {
            setErrorCode(SOAP_OK);
            fault_.clear();
            fault_detail_.clear();
            fault_subcode_.clear();
            is_auth_fault_ = false;
        }
    }

private:
    int error_code_;
    std::string fault_;
    std::string fault_detail_;
    std::string fault_subcode_;
    bool is_auth_fault_;
};


inline std::ostream& operator<<(std::ostream& os, const SimpleResponse& response)
{
    os << response.getCompleteFault();
    return os;
}

class DetailedResponse : public SimpleResponse
{
public:
    DetailedResponse() : SimpleResponse(), fault_result_object_ptr_(nullptr), soap_header_ptr_(nullptr)
    {
    }

    explicit DetailedResponse(const int errorCode, const std::string& rFault = std::string(), const std::string& rFaultDetail = std::string(),
                     const SOAP_ENV__Detail* pFaultObject = nullptr) :
        SimpleResponse(errorCode, rFault, rFaultDetail),
        fault_result_object_ptr_(pFaultObject ? soap_dup_SOAP_ENV__Detail(nullptr, nullptr, pFaultObject) : nullptr),
        soap_header_ptr_(nullptr)
    {
    }

    ~DetailedResponse() override
    {
        if (fault_result_object_ptr_) soap_del_SOAP_ENV__Detail(fault_result_object_ptr_);
        delete fault_result_object_ptr_;
        if (soap_header_ptr_) soap_del_SOAP_ENV__Header(soap_header_ptr_);
        delete soap_header_ptr_;
    }

    DetailedResponse(const DetailedResponse& rOther) :
        SimpleResponse(rOther),
        fault_result_object_ptr_(rOther.fault_result_object_ptr_
                                ? soap_dup_SOAP_ENV__Detail(nullptr, nullptr, rOther.fault_result_object_ptr_)
                                : nullptr),
        soap_header_ptr_(rOther.soap_header_ptr_ ? soap_dup_SOAP_ENV__Header(nullptr, nullptr, rOther.soap_header_ptr_) : nullptr)
    {
    }

    DetailedResponse& operator=(const DetailedResponse& rOther)
    {
        if (&rOther == this)
        {
            return *this;
        }
        SimpleResponse::operator=(rOther);
        if (fault_result_object_ptr_) soap_del_SOAP_ENV__Detail(fault_result_object_ptr_);
        delete fault_result_object_ptr_;
        this->fault_result_object_ptr_ =
            rOther.fault_result_object_ptr_
                ? soap_dup_SOAP_ENV__Detail(nullptr, nullptr, rOther.fault_result_object_ptr_)
                : nullptr;
        if (soap_header_ptr_) soap_del_SOAP_ENV__Header(soap_header_ptr_);
        delete soap_header_ptr_;
        this->soap_header_ptr_ = rOther.soap_header_ptr_
                                 ? soap_dup_SOAP_ENV__Header(nullptr, nullptr, rOther.soap_header_ptr_)
                                 : nullptr;
        return *this;
    }

    template <typename F>
    F* GetFaultObject()
    {
        if (fault_result_object_ptr_ && fault_result_object_ptr_->fault && fault_result_object_ptr_->__type)
        {
            return static_cast<F*>(fault_result_object_ptr_->fault);
        }
        return nullptr;
    }
    void SetEnvDetail(const SOAP_ENV__Detail* pFaultObject)
    {
        if (fault_result_object_ptr_) soap_del_SOAP_ENV__Detail(fault_result_object_ptr_);
        delete fault_result_object_ptr_;
        fault_result_object_ptr_ = pFaultObject ? soap_dup_SOAP_ENV__Detail(nullptr, nullptr, pFaultObject) : nullptr;
    }

    [[nodiscard]] const SOAP_ENV__Header* GetSoapHeader() const { return soap_header_ptr_; }

    void SetSoapHeader(const SOAP_ENV__Header* pSoapHeader)
    {
        if (soap_header_ptr_) soap_del_SOAP_ENV__Header(soap_header_ptr_);
        delete soap_header_ptr_;
        this->soap_header_ptr_ = pSoapHeader ? soap_dup_SOAP_ENV__Header(nullptr, nullptr, pSoapHeader) : nullptr;
    }

    [[nodiscard]] std::string getSoapHeaderMessageId() const
    {
        if (soap_header_ptr_)
        {
            return soap_header_ptr_->wsa5__MessageID;
        }
        return {};
    }

    [[nodiscard]] std::string getSoapHeaderRelatesTo() const
    {
        if (soap_header_ptr_ && soap_header_ptr_->wsa5__RelatesTo && soap_header_ptr_->wsa5__RelatesTo->__item)
        {
            return {soap_header_ptr_->wsa5__RelatesTo->__item};
        }
        return {};
    }

    [[nodiscard]] std::string getSoapHeaderAction() const
    {
        if (soap_header_ptr_ && soap_header_ptr_->wsa5__Action)
        {
            return {soap_header_ptr_->wsa5__Action};
        }
        return {};
    }

    [[nodiscard]] std::string GetSoapHeaderTo() const
    {
        if (soap_header_ptr_ && soap_header_ptr_->wsa5__To)
        {
            return {soap_header_ptr_->wsa5__To};
        }
        return {};
    }

    void populateFromCtx(const std::shared_ptr<SoapContext>& soap_ctx) override
    {
        SimpleResponse::populateFromCtx(soap_ctx);
        if (const auto errorCode = soap_ctx->GetFaultCode(); errorCode != SOAP_OK)
        {
            SetSoapHeader(nullptr);
            if (const auto pSoap = soap_ctx->Acquire(); pSoap->fault) SetEnvDetail(pSoap->fault->SOAP_ENV__Detail);
            soap_ctx->Release();
        }
        else
        {
            SetEnvDetail(nullptr);
            const auto pSoap = soap_ctx->Acquire();
            SetSoapHeader(pSoap->header);
            soap_ctx->Release();
        }
    }

private:
    SOAP_ENV__Detail* fault_result_object_ptr_;
    SOAP_ENV__Header* soap_header_ptr_;
};

template <class T, class Deleter = SoapDeleter<T>, class Duplicator = SoapDuplicator<T>>
class Response final : public DetailedResponse
{
public:
    Response() : DetailedResponse(), deleter_(), duplicator_(), result_object_ptr_(nullptr)
    {
    }
    explicit Response(const int errorCode, const std::string& rFault = std::string(), const std::string& rFaultDetail = std::string(),
             const T* pResultObject = nullptr,
             const SOAP_ENV__Detail* pFaultObject = nullptr) :
        DetailedResponse(errorCode, rFault, rFaultDetail, pFaultObject),
        deleter_(),
        duplicator_(),
        result_object_ptr_(pResultObject ? duplicator_(pResultObject) : nullptr)
    {
    }

    explicit Response(const T* pResultObject) :
        DetailedResponse(), deleter_(), duplicator_(),
        result_object_ptr_(pResultObject ? duplicator_(pResultObject) : nullptr)
    {
    }

    ~Response() override { deleter_(result_object_ptr_); }

    Response(const Response& rOther) :
        DetailedResponse(rOther),
        deleter_(rOther.deleter_),
        duplicator_(rOther.duplicator_),
        result_object_ptr_(rOther.result_object_ptr_ ? duplicator_(rOther.result_object_ptr_) : nullptr)
    {
    }

    Response& operator=(const Response& rOther)
    {
        if (&rOther == this)
        {
            return *this;
        }
        DetailedResponse::operator=(rOther);
        this->deleter_(this->result_object_ptr_);
        this->result_object_ptr_ = rOther.result_object_ptr_ ? duplicator_(rOther.result_object_ptr_) : nullptr;
        return *this;
    }

    //! Get the result object of a WS response
    const T* GetResultObject() const { return result_object_ptr_; }

    //! Set the result object of a WS response
    void SetResultObject(const T* pResultObject)
    {
        this->deleter_(this->result_object_ptr_);
        this->result_object_ptr_ = pResultObject ? duplicator_(pResultObject) : nullptr;
    }

    [[nodiscard]] bool isFault() const override { return DetailedResponse::isFault() || !GetResultObject(); }

    /*!
     *
     * \brief Builds a response object
     *
     */
    class Builder
    {
    public:
        Builder() : result_()
        {
        }

        Builder& From(const std::shared_ptr<SoapContext>& soap_ctx, const T* result_object_ptr = nullptr)
        {
            result_.populateFromCtx(soap_ctx);
            if (const auto errorCode = soap_ctx->GetFaultCode(); errorCode != SOAP_OK)
            {
                result_.SetResultObject(nullptr);
            }
            else
            {
                result_.SetResultObject(result_object_ptr);
            }
            return *this;
        }

        Response<T, Deleter, Duplicator> Build() const { return result_; }

    private:
        Response<T, Deleter, Duplicator> result_;
    };

private:
    Deleter deleter_;
    Duplicator duplicator_;
    T* result_object_ptr_;
};

template <class T>
class ArbitraryResponse final : public DetailedResponse
{
public:
    ArbitraryResponse() : DetailedResponse(), result_object_()
    {
    }
    explicit ArbitraryResponse(const int errorCode, const std::string& rFault = std::string(), const std::string& rFaultDetail = std::string(),
                      const SOAP_ENV__Detail* pFaultObject = nullptr) :
        DetailedResponse(errorCode, rFault, rFaultDetail, pFaultObject), result_object_()
    {
    }

    explicit ArbitraryResponse(const DetailedResponse& rOther) : DetailedResponse(rOther), result_object_()
    {
    }

    ArbitraryResponse(const ArbitraryResponse& rOther) : DetailedResponse(rOther), result_object_(rOther.result_object_)
    {
    }

    ArbitraryResponse& operator=(const ArbitraryResponse& rOther)
    {
        if (&rOther == this)
        {
            return *this;
        }
        DetailedResponse::operator=(rOther);
        result_object_ = rOther.result_object_;
        return *this;
    }

    ArbitraryResponse& operator=(const DetailedResponse& rOther)
    {
        if (&rOther == this)
        {
            return *this;
        }
        DetailedResponse::operator=(rOther);
        result_object_ = T();
        return *this;
    }

    T GetResultObject() const { return result_object_; }
    void SetResultObject(const T& rResultObject) { result_object_ = rResultObject; }

    class Builder
    {
    public:
        Builder() : arb_result_()
        {
        }

        Builder& From(const std::shared_ptr<SoapContext>& soap_ctx, const T& result_object)
        {
            arb_result_.populateFromCtx(soap_ctx);
            if (const auto errorCode = soap_ctx->GetFaultCode(); errorCode == SOAP_OK)
            {
                arb_result_.SetResultObject(result_object);
            }
            return *this;
        }

        Builder& From(const std::shared_ptr<SoapContext>& soap_ctx)
        {
            arb_result_.populateFromCtx(soap_ctx);
            return *this;
        }

        ArbitraryResponse<T> Build() const { return arb_result_; }

    private:
        ArbitraryResponse<T> arb_result_;
    };

private:
    T result_object_;
};
#endif //RESPONSE_H
