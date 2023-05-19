#include <dunenpc/dunenpc.hpp>

namespace dunenpc {

DuneClient::DuneClient() : nopayloadclient::NoPayloadClient() {
}

DuneClient::DuneClient(const std::string& gt_name) : nopayloadclient::NoPayloadClient(gt_name) {
}

json DuneClient::getUrl(const std::string& pl_type, long long run_number) {
    json resp = nopayloadclient::NoPayloadClient::getPayloadIOVs(run_number, 0);
    if (resp["code"] != 0) return resp;
    json payload_iovs = resp["msg"];
    if (!payload_iovs.contains(pl_type)) {
        return nopayloadclient::DataBaseException("No valid payload with type " + pl_type).jsonify();
    }
    json payload_iov = payload_iovs[pl_type];
    if (payload_iov["major_iov_end"] < run_number) {
        return nopayloadclient::DataBaseException("No valid payload with type " + pl_type).jsonify();
    }
    return makeResp(payload_iov["payload_url"]);
}

json DuneClient::insertPayload(std::string pl_type, std::string file_url,
                           long long run_number_start) {
    return nopayloadclient::NoPayloadClient::insertPayload(pl_type, file_url, run_number_start, 0);
}

json DuneClient::insertPayload(std::string pl_type, std::string file_url,
                           long long run_number_start, long long run_number_end) {
    return nopayloadclient::NoPayloadClient::insertPayload(pl_type, file_url, run_number_start, 0, run_number_end, 0);
}

}
