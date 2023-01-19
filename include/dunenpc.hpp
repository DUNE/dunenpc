#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace dunenpc {

    // Reading
    nlohmann::json get(std::string gt_name, std::string pl_type,
                       long long run, long long subrun);

    // Writing
    nlohmann::json createPayloadType(std::string name);
    nlohmann::json createGlobalTag(std::string name);
    nlohmann::json deleteGlobalTag(std::string name);
    nlohmann::json lockGlobalTag(std::string name);
    nlohmann::json unlockGlobalTag(std::string name);
    nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                                 long long run_start, long long subrun_start);
    nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                                 long long run_start, long long subrun_start,
                                 long long run_end, long long subrun_end);

     // Helper (Read-only)
     nlohmann::json getSize();
     nlohmann::json getPayloadTypes();
     nlohmann::json getGlobalTags();
     nlohmann::json checkConnection();
     nlohmann::json getConfDict();

}
