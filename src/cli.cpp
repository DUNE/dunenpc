#include <dunenpc/cli.hpp>

namespace dunenpc {

CLI::CLI() {
    insertCommand("getUrl", &CLI::getUrl);
    insertCommand("insertPayload", &CLI::insertPayload);
}

json CLI::getUrl(DuneClient& c, int& argc, char* argv[]) {
    std::cout << "CLI::getUrl()" << std::endl;
    std::string gt_name = argv[2];
    std::string type = argv[3];
    long long run_number = std::atoi(argv[4]);
    c.setGlobalTag(gt_name);
    return c.getUrl(type, run_number);
}

json CLI::insertPayload(DuneClient& c, int& argc, char* argv[]){
    std::string gt = argv[2];
    std::string pt = argv[3];
    std::string file_url = argv[4];
    long long run_number_start = std::atoi(argv[5]);
    c.setGlobalTag(gt);
    if (argc == 6) {
        return c.insertPayload(pt, file_url, run_number_start);
    }
    else if (argc == 7) {
        long long run_number_end = std::atoi(argv[6]);
        return c.insertPayload(pt, file_url, run_number_start, run_number_end);
    }
    std::string t = "insertPayload takes 4 or 5 arguments (" + std::to_string(argc-2) + " were given).";
    return nopayloadclient::BaseException(t).jsonify();
}


}

int main(int argc, char *argv[])
{
    dunenpc::CLI cli;
    dunenpc::DuneClient client;
    std::cout << cli.callCommand(argv[1], &client, argc, *argv).dump(4) << std::endl;

    return 0;
}
