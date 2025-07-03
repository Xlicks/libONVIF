//
// Created by licks on 24-7-3.
//
//Profile G
#ifndef ONVIF_RECORDING_CLIENT_H
#define ONVIF_RECORDING_CLIENT_H

#include "global.h"
#include "request.h"
#include "response.h"
#include "onvif_client.h"

struct OnvifRecordingClientImplementation;

class OnvifRecordingClient final : public OnvifClient
{
public:
    //类禁止拷贝和赋值
    DISALLOW_COPY_AND_ASSIGN(OnvifRecordingClient);
    explicit OnvifRecordingClient(const std::string &endpoint, std::shared_ptr<SoapContext> shared_ctx = std::make_shared<SoapContext>());
    ~OnvifRecordingClient() override;

    static std::string GetServiceNamespace() { return "http://www.onvif.org/ver10/recording/wsdl"; }
    Response<_trc__GetServiceCapabilitiesResponse> GetServiceCapabilities(Request<_trc__GetServiceCapabilities> &request) const;
    Response<_trc__CreateRecordingResponse> CreateRecording(Request<_trc__CreateRecording> &request) const;
    Response<_trc__DeleteRecordingResponse> DeleteRecording(Request<_trc__DeleteRecording> &request) const;
    Response<_trc__GetRecordingsResponse> GetRecordings(Request<_trc__GetRecordings> &request) const;
    Response<_trc__SetRecordingConfigurationResponse> SetRecordingConfiguration(Request<_trc__SetRecordingConfiguration> &request) const;
    Response<_trc__GetRecordingConfigurationResponse> GetRecordingConfiguration(Request<_trc__GetRecordingConfiguration> &request) const;
    Response<_trc__GetRecordingOptionsResponse> GetRecordingOptions(Request<_trc__GetRecordingOptions> &request) const;
    Response<_trc__CreateTrackResponse> CreateTrack(Request<_trc__CreateTrack> &request) const;
    Response<_trc__DeleteTrackResponse> DeleteTrack(Request<_trc__DeleteTrack> &request) const;
    Response<_trc__GetTrackConfigurationResponse> GetTrackConfiguration(Request<_trc__GetTrackConfiguration> &request) const;
    Response<_trc__SetTrackConfigurationResponse> SetTrackConfiguration(Request<_trc__SetTrackConfiguration> &request) const;
    Response<_trc__CreateRecordingJobResponse> CreateRecordingJob(Request<_trc__CreateRecordingJob> &request) const;
    Response<_trc__DeleteRecordingJobResponse> DeleteRecordingJob(Request<_trc__DeleteRecordingJob> &request) const;
    Response<_trc__GetRecordingJobsResponse> GetRecordingJobs(Request<_trc__GetRecordingJobs> &request) const;
    Response<_trc__SetRecordingJobConfigurationResponse> SetRecordingJobConfiguration(Request<_trc__SetRecordingJobConfiguration> &request) const;
    Response<_trc__GetRecordingJobConfigurationResponse> GetRecordingJobConfiguration(Request<_trc__GetRecordingJobConfiguration> &request) const;
    Response<_trc__SetRecordingJobModeResponse> SetRecordingJobMode(Request<_trc__SetRecordingJobMode> &request) const;
    Response<_trc__GetRecordingJobStateResponse> GetRecordingJobState(Request<_trc__GetRecordingJobState> &request) const;
    Response<_trc__ExportRecordedDataResponse> ExportRecordedData(Request<_trc__ExportRecordedData> &request) const;
    Response<_trc__StopExportRecordedDataResponse> StopExportRecordedData(Request<_trc__StopExportRecordedData> &request) const;
    Response<_trc__GetExportRecordedDataStateResponse> GetExportRecordedDataState(Request<_trc__GetExportRecordedDataState> &request) const;
private:
    OnvifRecordingClientImplementation* impl_;
};


#endif //ONVIF_RECORDING_CLIENT_H
