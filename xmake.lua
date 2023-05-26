add_rules("mode.debug", "mode.release")

add_requires("gflags 2.2.2", "glog 0.6.0", "gtest")

set_languages("c++11", "c++14")

target("leetcode")
    set_kind("binary")
    add_packages("gflags", "glog", "gtest")
    add_files("src/utils/**.cpp", "src/leetcode/**.cpp", 
        "src/sword_to_offer/**.cpp", "src/classical/**.cpp", "src/main.cpp")
    add_includedirs("include/")

-- 用于测试单个问题
target("test")
    set_kind("binary")
    add_packages("gflags", "glog", "gtest")
    add_files("src/utils/**.cpp", "src/leetcode/cpp/q0001.cpp", "src/main.cpp")
    add_includedirs("include/")