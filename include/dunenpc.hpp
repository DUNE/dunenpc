#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <nopayloadclient/nopayloadclient.hpp>

using json = nlohmann::json;

namespace dunenpc {

class Client : public nopayloadclient::Client {

using nopayloadclient::Client::Client;
public:
    json getUrlDict(long long iov);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long iov_start);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long iov_start, long long iov_end);
};

}
