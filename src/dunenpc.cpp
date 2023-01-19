#include <nopayloadclient.hpp>
#include <dunenpc.hpp>


namespace dunenpc {

// Reading
nlohmann::json get(std::string gt_name, std::string pl_type, long long iov){
    return nopayloadclient::get(gt_name, pl_type, 0, iov);
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
                             long long iov_start){
    return nopayloadclient::insertPayload(gt_name, pl_type, file_url, 0, iov_start);
}

nlohmann::json insertPayload(std::string gt_name, std::string pl_type, std::string file_url,
                             long long iov_start, long long iov_end){
    return nopayloadclient::insertPayload(gt_name, pl_type, file_url, 0, iov_start, 0, iov_end);
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
