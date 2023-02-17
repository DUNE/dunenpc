#include <dunenpc/dunenpc.hpp>

namespace dunenpc {

json Client::getUrlDict(long long run_number) {
    return nopayloadclient::Client::getUrlDict(run_number, 0);
}

json Client::insertPayload(std::string pl_type, std::string file_url,
                           long long run_number_start) {
    return nopayloadclient::Client::insertPayload(pl_type, file_url, run_number_start, 0);
}

json Client::insertPayload(std::string pl_type, std::string file_url,
                           long long run_number_start, long long run_number_end) {
    return nopayloadclient::Client::insertPayload(pl_type, file_url, run_number_start, 0, run_number_end, 0);
}

}
