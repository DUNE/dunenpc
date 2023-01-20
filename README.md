## Welcome to sphenixnpx!
### Table of contents
* [Introduction](#introduction)
* [Setup](#setup)
* [Testing](#testing)
* [Usage](#usage)

### Introduction
This DUNE-specific client-side library is meant to communicate
with NoPayloadDB (https://github.com/bnlnpps/nopayloaddb). It is
a simple modification of the more general nopayloadclient
(https://github.com/ligerlac/nopayloadclient).

### Setup
#### preface: install ```nopayloadclient```
As this library builds on ```nopayloadclient```, install it first
as described here: https://github.com/ligerlac/nopayloadclient.

#### install ```dunenpc```
If a custom install path was chosen for ```nopayloadclient```,
configure ```dunenpc``` to the same one:
```shell
source setup_custom_install_path.sh /absolute/install/path
```
In the project folder, configure cmake and compile
```shell
cmake -S . -B build && cmake --build build/
```
Install the client
```shell
cmake --install build/
```
Configure the client by specifying the config file in
an env variable
```shell
export NOPAYLOADCLIENT_CONF=/path/to/config.json
```
If this is not done, the default parameters of ```nopayloadclient``` will
be assumed.

### Testing
The following command activates testing, reconfigures cmake, recompiles the code
and runs the tests
```
cmake -DBUILD_TESTING=ON -S . -B build && cmake --build build/ && cd build/ && ctest --verbose && cd ..
```

### Usage
To use this library in an independent project, include its
header and the widely-spread nlohmann json header-only lib
(https://github.com/nlohmann/json)
```c
#include <nlohmann/json.hpp>
#include <dunenpc.hpp>
```
Payloads can be inserted via
```c
dunenpc::insertPayload(<gt_name>, <gt_type>, <local_url>, <run_number>, <subrun_number>);
```
and their url can be retrieved via
```c
dunenpc::get(<gt_name>, <gt_type>, <run_number>, <subrun_number>);
```
Every method returns a nlohmann::json object with a response code and a
message body in the  following format:
```
{'code': <code>, 'msg': <message>}
```
Currently, the following response codes are implemented:
```
0: ok
1: base error (no further details)
2: error when handling a payload
3: error in the database (server-side)
```
Examples on how to use this tool in a c++ program can be found in the ```examples/```
folder. To compile ```standalone.cpp```, run the following command
```shell
 g++ -std=c++17 standalone.cpp -lnopayloadclient -ldunenpc -lcurl
```

#### Usage through command line interface
```examples/cli_dune.cpp``` is an implementation of a command line interface.
It is compiled and installed along the rest of the project and can be run via 
```shell
cli_dunenpc <command> <parameters>
```
The available commands are: get, createGlobalTag, createPayloadType, lockGlobalTag,
unlockGlobalTag, deleteGlobalTag, insertPayload (overloaded), getSize,
getPayloadTypes, getGlobalTags, checkConnection, and getConfDict. Example workflow:
```shell
export NOPAYLOADCLIENT_CONF=/path/to/config.json
cli_dunenpc checkConnection
cli_dunenpc createGlobalTag example_gt
cli_dunenpc getGlobalTags
cli_dunenpc createPayloadType example_pt
cli_dunenpc getPayloadTypes
cli_dunenpc insertPayload example_gt example_pt /tmp/file.dat 7 11
cli_dunenpc get example_gt example_pt 9 13
cli_dunenpc getSize
```