//
// Created by licks on 24-7-3.
//

#include "onvif_recording_client.h"
#include "soapRecordingBindingProxy.h"

struct OnvifRecordingClientImplementation
{
    explicit OnvifRecordingClientImplementation(OnvifRecordingClient* rc_ptr)
        : recording_client_ptr(rc_ptr),
          rb_proxy(recording_client_ptr->GetContext()->Acquire())
    {
        soap_set_namespaces(rb_proxy.soap, SoapContext::GetDefaultNamespaces());
        recording_client_ptr->GetContext()->Release();
    }
    OnvifRecordingClient* recording_client_ptr;
    RecordingBindingProxy rb_proxy;
};

OnvifRecordingClient::OnvifRecordingClient(const std::string& endpoint, std::shared_ptr<SoapContext> shared_ctx)
        : OnvifClient(endpoint, std::move(shared_ctx)), impl_(new (std::nothrow) OnvifRecordingClientImplementation(this))
{
}

OnvifRecordingClient::~OnvifRecordingClient()
{
    delete impl_;
}

Response<_trc__GetServiceCapabilitiesResponse> OnvifRecordingClient::GetServiceCapabilities(
    Request<_trc__GetServiceCapabilities>& request) const
{
    _trc__GetServiceCapabilitiesResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetServiceCapabilities(GetEndpoint().c_str(),
                                               !request.GetSoapAction().empty() ? request.GetSoapAction().c_str() : nullptr,
                                               &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetServiceCapabilitiesResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__CreateRecordingResponse> OnvifRecordingClient::CreateRecording(Request<_trc__CreateRecording>& request) const
{
    _trc__CreateRecordingResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.CreateRecording(GetEndpoint().c_str(),
                                        !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__CreateRecordingResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__DeleteRecordingResponse> OnvifRecordingClient::DeleteRecording(Request<_trc__DeleteRecording>& request) const
{
    _trc__DeleteRecordingResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.DeleteRecording(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__DeleteRecordingResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingsResponse> OnvifRecordingClient::GetRecordings(Request<_trc__GetRecordings>& request) const
{
    _trc__GetRecordingsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordings(GetEndpoint().c_str(),
                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                     &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__SetRecordingConfigurationResponse> OnvifRecordingClient::SetRecordingConfiguration(
    Request<_trc__SetRecordingConfiguration>& request) const
{
    _trc__SetRecordingConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.SetRecordingConfiguration(GetEndpoint().c_str(),
                                              !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                               &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__SetRecordingConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingConfigurationResponse> OnvifRecordingClient::GetRecordingConfiguration(
    Request<_trc__GetRecordingConfiguration>& request) const
{
    _trc__GetRecordingConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordingConfiguration(GetEndpoint().c_str(),
                                             !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                               &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingOptionsResponse> OnvifRecordingClient::GetRecordingOptions(
    Request<_trc__GetRecordingOptions>& request) const
{
    _trc__GetRecordingOptionsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordingOptions(GetEndpoint().c_str(),
                                       !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingOptionsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__CreateTrackResponse> OnvifRecordingClient::CreateTrack(Request<_trc__CreateTrack>& request) const
{
    _trc__CreateTrackResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.CreateTrack(GetEndpoint().c_str(),
                                  !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                    &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__CreateTrackResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__DeleteTrackResponse> OnvifRecordingClient::DeleteTrack(Request<_trc__DeleteTrack>& request) const
{
    _trc__DeleteTrackResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.DeleteTrack(GetEndpoint().c_str(),
                                 !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                    &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__DeleteTrackResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetTrackConfigurationResponse> OnvifRecordingClient::GetTrackConfiguration(
    Request<_trc__GetTrackConfiguration>& request) const
{
    _trc__GetTrackConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetTrackConfiguration(GetEndpoint().c_str(),
                                          !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetTrackConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__SetTrackConfigurationResponse> OnvifRecordingClient::SetTrackConfiguration(
    Request<_trc__SetTrackConfiguration>& request) const
{
    _trc__SetTrackConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.SetTrackConfiguration(GetEndpoint().c_str(),
                                         !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__SetTrackConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__CreateRecordingJobResponse> OnvifRecordingClient::CreateRecordingJob(
    Request<_trc__CreateRecordingJob>& request) const
{
    _trc__CreateRecordingJobResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.CreateRecordingJob(GetEndpoint().c_str(),
                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__CreateRecordingJobResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__DeleteRecordingJobResponse> OnvifRecordingClient::DeleteRecordingJob(
    Request<_trc__DeleteRecordingJob>& request) const
{
    _trc__DeleteRecordingJobResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.DeleteRecordingJob(GetEndpoint().c_str(),
                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__DeleteRecordingJobResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingJobsResponse> OnvifRecordingClient::GetRecordingJobs(
    Request<_trc__GetRecordingJobs>& request) const
{
    _trc__GetRecordingJobsResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordingJobs(GetEndpoint().c_str(),
                                   !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                        &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingJobsResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__SetRecordingJobConfigurationResponse> OnvifRecordingClient::SetRecordingJobConfiguration(
    Request<_trc__SetRecordingJobConfiguration>& request) const
{
    _trc__SetRecordingJobConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.SetRecordingJobConfiguration(GetEndpoint().c_str(),
                                            !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__SetRecordingJobConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingJobConfigurationResponse> OnvifRecordingClient::GetRecordingJobConfiguration(
    Request<_trc__GetRecordingJobConfiguration>& request) const
{
    _trc__GetRecordingJobConfigurationResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordingJobConfiguration(GetEndpoint().c_str(),
                                           !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                                &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingJobConfigurationResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__SetRecordingJobModeResponse> OnvifRecordingClient::SetRecordingJobMode(
    Request<_trc__SetRecordingJobMode>& request) const
{
    _trc__SetRecordingJobModeResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.SetRecordingJobMode(GetEndpoint().c_str(),
                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__SetRecordingJobModeResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetRecordingJobStateResponse> OnvifRecordingClient::GetRecordingJobState(
    Request<_trc__GetRecordingJobState>& request) const
{
    _trc__GetRecordingJobStateResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetRecordingJobState(GetEndpoint().c_str(),
                                   !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetRecordingJobStateResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__ExportRecordedDataResponse> OnvifRecordingClient::ExportRecordedData(
    Request<_trc__ExportRecordedData>& request) const
{
    _trc__ExportRecordedDataResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.ExportRecordedData(GetEndpoint().c_str(),
                                    !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__ExportRecordedDataResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__StopExportRecordedDataResponse> OnvifRecordingClient::StopExportRecordedData(
    Request<_trc__StopExportRecordedData>& request) const
{
    _trc__StopExportRecordedDataResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.StopExportRecordedData(GetEndpoint().c_str(),
                                   !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__StopExportRecordedDataResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}

Response<_trc__GetExportRecordedDataStateResponse> OnvifRecordingClient::GetExportRecordedDataState(
    Request<_trc__GetExportRecordedDataState>& request) const
{
    _trc__GetExportRecordedDataStateResponse response_object;
    const auto soap_ptr = AcquireContext();
    do
    {
        impl_->rb_proxy.GetExportRecordedDataState(GetEndpoint().c_str(),
                                   !request.GetSoapAction().empty()? request.GetSoapAction().c_str() : nullptr,
                                            &request, response_object);
    } while (ReTry(soap_ptr));
    auto response = Response<_trc__GetExportRecordedDataStateResponse>::Builder();
    response.From(GetContext(), &response_object);
    ReleaseContext(soap_ptr);
    return response.Build();
}
