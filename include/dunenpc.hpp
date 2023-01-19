#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace dunenpc {

    // Reading
    nlohmann::json get(std::string gt_name, std::string pl_type, long long iov);

    // Writing
    nlohmann::json createPayloadType(std::string name);
    nlohmann::json createGlobalTag(std::string name);
    nlohmann::json deleteGlobalTag(std::string name);
    nlohmann::json lockGlobalTag(std::string name);
    nlohmann::json unlockGlobalTag(std::string name);
    nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                                 long long iov_start);
    nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                                 long long iov_start, long long iov_end);

     // Helper (Read-only)
     nlohmann::json getSize();
     nlohmann::json getPayloadTypes();
     nlohmann::json getGlobalTags();
     nlohmann::json checkConnection();
     nlohmann::json getConfDict();

}
