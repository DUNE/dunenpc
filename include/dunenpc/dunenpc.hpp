#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <nopayloadclient/nopayloadclient.hpp>

using json = nlohmann::json;

namespace dunenpc {

class Client : public nopayloadclient::Client {

using nopayloadclient::Client::Client;
public:
    json getUrlDict(long long run_number);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long run_number_start);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long run_number_start, long long run_number_end);
};

}
