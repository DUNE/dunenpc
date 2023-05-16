#include <dunenpc/dunenpc.hpp>

namespace dunenpc {

DuneClient::DuneClient() : nopayloadclient::NoPayloadClient() {
}

DuneClient::DuneClient(const std::string& gt_name) : nopayloadclient::NoPayloadClient(gt_name) {
}

json DuneClient::getUrlDict(long long run_number) {
    return nopayloadclient::NoPayloadClient::getUrlDict(run_number, 0);
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
