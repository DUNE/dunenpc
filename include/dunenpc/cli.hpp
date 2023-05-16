#pragma once

#include <nopayloadclient/cli.hpp>
#include <nopayloadclient/exception.hpp>
#include <dunenpc/dunenpc.hpp>

namespace dunenpc {

class CLI : public nopayloadclient::CLI {
public:
    CLI();
    json getUrlDict(DuneClient& c, int& argc, char* argv[]);
    json insertPayload(DuneClient& c, int& argc, char* argv[]);
};

}
