#include <dunenpc.hpp>

namespace dunenpc {

json Client::getUrlDict(long long iov) {
    return nopayloadclient::Client::getUrlDict(0, iov);
}

json Client::insertPayload(std::string pl_type, std::string file_url,
                           long long iov_start) {
    return nopayloadclient::Client::insertPayload(pl_type, file_url, 0, iov_start);
}

json Client::insertPayload(std::string pl_type, std::string file_url,
                           long long iov_start, long long iov_end) {
    return nopayloadclient::Client::insertPayload(pl_type, file_url, 0, iov_start, 0, iov_end);
}

}
