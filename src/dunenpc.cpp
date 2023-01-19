#include <nopayloadclient/nopayloadclient.hpp>
#include <dunenpc.hpp>


namespace dunenpc {

// Reading
nlohmann::json get(std::string gt_name, std::string pl_type,
                   long long run, long long subrun){
    return nopayloadclient::get(gt_name, pl_type, run, subrun);
}


// Writing
nlohmann::json createGlobalTag(std::string name) {
    return nopayloadclient::createGlobalTag(name);
}

nlohmann::json lockGlobalTag(std::string name) {
    return nopayloadclient::lockGlobalTag(name);
}

nlohmann::json unlockGlobalTag(std::string name) {
    return nopayloadclient::unlockGlobalTag(name);
}

nlohmann::json deleteGlobalTag(std::string name) {
    return nopayloadclient::deleteGlobalTag(name);
}

nlohmann::json createPayloadType(std::string name) {
    return nopayloadclient::createPayloadType(name);
}

nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                             long long run_start, long long subrun_start){
    return nopayloadclient::insertPayload(gt_name, pl_type, file_url,
                                          run_start, subrun_start);
}

nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                             long long run_start, long long subrun_start,
                             long long run_end, long long subrun_end){
    return nopayloadclient::insertPayload(gt_name, pl_type, file_url,
                                          run_start, subrun_start, run_end, subrun_end);
}

// Helper (Read-only)
nlohmann::json getSize() {
    return nopayloadclient::getSize();
}
nlohmann::json getPayloadTypes() {
    return nopayloadclient::getPayloadTypes();
}
nlohmann::json getGlobalTags() {
    return nopayloadclient::getGlobalTags();
}
nlohmann::json checkConnection() {
    return nopayloadclient::checkConnection();
}
nlohmann::json getConfDict() {
    return nopayloadclient::getConfDict();
}

}
