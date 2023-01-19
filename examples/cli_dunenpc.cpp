#include <iostream>
#include <dunenpc.hpp>

void get(char *argv[]){
  std::string global_tag = argv[2];
  std::string pl_type = argv[3];
  int iov = std::atoi(argv[4]);
  std::cout << dunenpc::get(global_tag, pl_type, iov) << std::endl;
}

void createGlobalTag(char *argv[]) {
  std::string gt = argv[2];
  std::cout << dunenpc::createGlobalTag(gt) << std::endl;
}

void createPayloadType(char *argv[]) {
  std::string pt = argv[2];
  std::cout << dunenpc::createPayloadType(pt) << std::endl;
}

void lockGlobalTag(char *argv[]) {
  std::string gt = argv[2];
  std::cout << dunenpc::lockGlobalTag(gt) << std::endl;
}

void unlockGlobalTag(char *argv[]) {
  std::string gt = argv[2];
  std::cout << dunenpc::unlockGlobalTag(gt) << std::endl;
}

void deleteGlobalTag(char *argv[]) {
  std::string gt = argv[2];
  std::cout << dunenpc::deleteGlobalTag(gt) << std::endl;
}

void insertPayload(int argc, char *argv[]) {
  std::string gt = argv[2];
  std::string pt = argv[3];
  std::string file_url = argv[4];
  long long iov_start = std::atoi(argv[5]);
  if (argc == 6) {
      std::cout << dunenpc::insertPayload(gt, pt, file_url, iov_start) << std::endl;
  }
  else if (argc == 7) {
      long long iov_end = std::atoi(argv[6]);
      std::cout << dunenpc::insertPayload(gt, pt, file_url, iov_start, iov_end) << std::endl;
  }
  else {
      std::cout << "insertPayload takes 4 or 5 arguments (" << argc-2 << " were given)." << std::endl;
  }
}


int main(int argc, char *argv[])
{
  std::string command = argv[1];
  //std::cout << "command = " << command << std::endl;
  if (command == "get") {
      get(argv);
  }
  else if (command == "createGlobalTag") {
      createGlobalTag(argv);
  }
  else if (command == "createPayloadType") {
      createPayloadType(argv);
  }
  else if (command == "lockGlobalTag") {
      lockGlobalTag(argv);
  }
  else if (command == "unlockGlobalTag") {
      unlockGlobalTag(argv);
  }
  else if (command == "insertPayload") {
      insertPayload(argc, argv);
  }
  else if (command == "deleteGlobalTag") {
      deleteGlobalTag(argv);
  }
  else if (command == "getSize") {
      std::cout << dunenpc::getSize() << std::endl;
  }
  else if (command == "getGlobalTags") {
      std::cout << dunenpc::getGlobalTags() << std::endl;
  }
  else if (command == "getPayloadTypes") {
      std::cout << dunenpc::getPayloadTypes() << std::endl;
  }
  else if (command == "checkConnection") {
      std::cout << dunenpc::checkConnection() << std::endl;
  }
  else {
      std::cout << "unknown command <" << command << ">. (pick from [get, createGlobalTag, createPayloadType, lockGlobalTag, unlockGlobalTag, insertPayload, deleteGlobalTag, checkConnection]" << std::endl;
  }
  return 0;
}
