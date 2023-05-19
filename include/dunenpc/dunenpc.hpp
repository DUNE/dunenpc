#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <nopayloadclient/nopayloadclient.hpp>


namespace dunenpc {

using json = nlohmann::json;

class DuneClient : public nopayloadclient::NoPayloadClient {

public:
    DuneClient();
    DuneClient(const std::string& gt_name);

    json getUrl(const std::string& pl_type, long long run_number);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long run_number_start);
    json insertPayload(std::string pl_type, std::string file_url,
                       long long run_number_start, long long run_number_end);
};

}
