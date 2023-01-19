#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <time.h>
#include <filesystem>

#include <dunenpc.hpp>


int getPayloadNumber() {
  nlohmann::json conf_dict = dunenpc::getConfDict()["msg"];
  const std::filesystem::path pl_path{conf_dict["write_dir"]};
  std::filesystem::recursive_directory_iterator pl_iterator{pl_path};
  int n = 0;
  for (auto const& dir_entry : pl_iterator) {
      if (!std::filesystem::is_directory(dir_entry.path())) n++;
  }
  return n;
}

int createRandomPayload(char filename[]) {
  std::filesystem::remove(filename);
  std::ofstream my_file(filename);
  for (int i=0; i<10; i++) {
    my_file << std::to_string(random());
  }
  my_file.close();
  return 0;
}

long long randLong(long long lower, long long upper) {
    return lower + (random() % (upper-lower+1));
}


int main()
{
  std::cout << "initializing helper variables ..." << std::endl;
  char my_local_url[] = "/tmp/file.dat";
  char my_local_url_2[] = "/tmp/file_2.dat";

  nlohmann::json resp;
  srandom(time(NULL));

  long long run_start = randLong(0, 1e6);
  long long subrun_start = randLong(0, 1e6);
  long long run_end = randLong(run_start, 10e6);
  long long subrun_end = randLong(subrun_start, 10e6);
  long long run = randLong(run_start, run_end);
  long long subrun = randLong(subrun_start, subrun_end);

  int n_pl_0 = getPayloadNumber();

  // create random payload files
  if (createRandomPayload(my_local_url) == 1) return 1;
  if (createRandomPayload(my_local_url_2) == 1) return 1;

  resp = dunenpc::checkConnection();
  std::cout << resp << std::endl;

  // create the global tag if it does not exist
  resp = dunenpc::deleteGlobalTag("my_gt");
  std::cout << resp << std::endl;

  resp = dunenpc::createGlobalTag("my_gt");
  std::cout << resp << std::endl;

  // create the payload type if it does not exist
  resp = dunenpc::createPayloadType("my_pt");
  std::cout << resp << std::endl;

  // insert should work
  resp = dunenpc::insertPayload("my_gt", "my_pt", my_local_url,
                                        run_start, subrun_start,
                                        run_end, subrun_end);
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // number of payloads should have increased by one
  int n_pl_1 = getPayloadNumber();
  if (n_pl_1 != (n_pl_0 + 1)) return 1;

  // getting the url from the DB again should work
  resp = dunenpc::get("my_gt", "my_pt", run, subrun);
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // inserting another iov with the same payload should work...
  resp = dunenpc::insertPayload("my_gt", "my_pt", my_local_url,
                                        run, subrun,
                                        run_end, subrun_end);
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // ... but not change the number of payloads
  int n_pl_2 = getPayloadNumber();
  if (n_pl_2 != n_pl_1) return 1;

  // trying to lock the global tag
  resp = dunenpc::lockGlobalTag("my_gt");
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // should not be able to write to a locked gt ...
  resp = dunenpc::insertPayload("my_gt", "my_pt", my_local_url,
                                        run, subrun);
  std::cout << resp << std::endl;
  if (resp["code"] == 0) return 1;

  // ... except if the IOV does not overlap with existing
  resp = dunenpc::insertPayload("my_gt", "my_pt", my_local_url,
                                        run_end, subrun_end);
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // deletion of locked global tag should fail
  resp = dunenpc::deleteGlobalTag("my_gt");
  std::cout << resp << std::endl;
  if (resp["code"] == 0) return 1;

  // trying to unlock global tag
  resp = dunenpc::unlockGlobalTag("my_gt");
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // insertion should work again after unlocking
  resp = dunenpc::insertPayload("my_gt", "my_pt", my_local_url,
                                        run, subrun);
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // deletion of unlocked global tag should work
  resp = dunenpc::deleteGlobalTag("my_gt");
  std::cout << resp << std::endl;
  if (resp["code"] != 0) return 1;

  // retrieval after deletion should fail
  resp = dunenpc::get("my_gt", "my_pt", run, subrun);
  std::cout << resp << std::endl;
  if (resp["code"] == 0) return 1;


  // ++++++++++++++++++++++++++++++
  //    THINGS THAT SHOULD FAIL
  // ++++++++++++++++++++++++++++++

  // try inserting to a global tag that does not exist should cause an error
  resp = dunenpc::insertPayload("non_existing_gt", "my_pt", my_local_url, 0, 0);
  std::cout<<resp<<std::endl;
  if (resp["code"]==0) return 1;

  // ... same for payload type that does not exist...
  resp = dunenpc::insertPayload("my_gt", "non_existing_type", my_local_url, 0, 0);
  std::cout<<resp<<std::endl;
  if (resp["code"]==0) return 1;

  // ... and if the payload file does not exist locally ...
  resp = dunenpc::insertPayload("my_gt", "my_pt", "non_existing_file", 0, 0);
  std::cout<<resp<<std::endl;
  if (resp["code"]==0) return 1;

  return EXIT_SUCCESS;
}
