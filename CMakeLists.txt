cmake_minimum_required(VERSION 2.8.12)
project(leetcode)

# depend gflags
find_package(gflags REQUIRED)
message(STATUS "depend gflags include: ${gflags_INCLUDE_DIR}")
message(STATUS "depend gflags lib: ${gflags_LIB}")
include_directories(${gflags_INCLUDE_DIR})
set(gflags_LIB gflags)
set(LIBS ${LIBS} ${gflags_LIB})

#depend gtest
find_package(GTest REQUIRED)
message(STATUS "depend gtest include: ${GTEST_INCLUDE_DIR}")
message(STATUS "depend gtest lib: ${GTEST_BOTH_LIBRARIES}")
include_directories(${GTEST_INCLUDE_DIR})
set(LIBS ${LIBS} ${GTEST_BOTH_LIBRARIES})

#depend glog
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
  MESSAGE(STATUS "current platform: Linux ")
  include(./FindGlog.cmake)
ELSEIF (APPLE)
  find_package(Glog REQUIRED)
  set(GLOG_LIBRARIES glog::glog)
ELSE ()
  message(STATUS "error:not support os")

ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
#find_package(Glog REQUIRED)
message(STATUS "depend glog include: ${GLOG_INCLUDE_DIRS}")
message(STATUS "depend glog lib: ${GLOG_LIBRARIES}")
set(GLOG_INCLUDE_DIRS ${GTEST_INCLUDE_DIR})
#set(GLOG_LIBRARIES glog::glog)
include_directories(${GLOG_INCLUDE_DIRS}) 
set(LIBS ${LIBS} ${GLOG_LIBRARIES})

# display depending libs
message(STATUS "depend libs: ${LIBS}")

# set include and compiler params
include_directories(include/)
add_definitions(-std=c++11)
add_definitions(-g)
add_definitions(-Wall)
set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

# set libs in src
add_subdirectory(src)
set(EXT_LIBS ${EXT_LIBS} utils)
message(STATUS "depend ext_libs: ${EXT_LIBS}")
message(STATUS "CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}")

# create executable files
aux_source_directory(./src DIR_SRC)
aux_source_directory(./src/e001_100 E100_DIR_SRC)
aux_source_directory(./src/other OTHER_DIR_SRC)
#set(E100_DIR_SRC src/e001_100/q0048.cpp)
#set(E100_DIR_SRC src/e001_100/q1276.cpp)
add_executable(${PROJECT_NAME} ${DIR_SRC} ${E100_DIR_SRC} ${OTHER_DIR_SRC})
target_link_libraries(${PROJECT_NAME} ${LIBS} ${EXT_LIBS})
