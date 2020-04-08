#include "leetcode.h"

int main(int argc, char ** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    google::SetStderrLogging(google::GLOG_INFO);
    // run testcases
    testing::InitGoogleTest();
    int ret = RUN_ALL_TESTS();
    google::ShutdownGoogleLogging();
    return ret;
}