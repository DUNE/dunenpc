#pragma once

#include <nopayloadclient/cli.hpp>
#include <dunenpc/dunenpc.hpp>

namespace dunenpc {

class CLI : public nopayloadclient::CLI {
public:
    CLI();
    json getUrlDict(Client& c, int& argc, char* argv[]);
    json insertPayload(Client& c, int& argc, char* argv[]);
};

}
