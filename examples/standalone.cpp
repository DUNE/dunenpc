#include <iostream>
#include <nlohmann/json.hpp> // every method returns a json object
#include <dunenpc.hpp>


int main()
{
  // ++++++++++++++++++++++++++++++
  //         PREPARATION
  // ++++++++++++++++++++++++++++++

  // make sure global tag & payload type exist
  std::cout << dunenpc::createGlobalTag("dune_ExampleGT_1") << std::endl;
  std::cout << dunenpc::createPayloadType("Beam") << std::endl;;

  // create json object to which the response is written
  nlohmann::json resp;


  // ++++++++++++++++++++++++++++++
  //         INSERTION
  // ++++++++++++++++++++++++++++++

  // try inserting payload
  resp = dunenpc::insertPayload("dune_ExampleGT_1", "Beam", "/tmp/file.dat", 0, 0);

  // analyse response: code==0 -> OK, code!=0 -> Not OK!
  if (resp["code"]!=0) {
    std::cout<<"something went wrong. error message: "<<resp["msg"]<<std::endl;
  }
  else {
    std::cout<<"all good. details: "<<resp["msg"]<<std::endl;
  }

  // w/o error handling, inserting a payload is a one-liner:
  resp = dunenpc::insertPayload("dune_ExampleGT_1", "Beam", "/tmp/file.dat", 0, 0);
  std::cout << resp << std::endl;


  // ++++++++++++++++++++++++++++++
  //          RETRIEVAL
  // ++++++++++++++++++++++++++++++

  resp = dunenpc::get("dune_ExampleGT_1", "Beam", 42, 42);
  std::cout << resp << std::endl;

  return 0;
}

