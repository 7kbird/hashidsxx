project(hashids)
cmake_minimum_required(VERSION 2.6)

option(HASHID_BUILD_TESTS "Enable test" OFF)
option(HASHID_BUILD_HASHIDSXX "Build hashidsxx executable" OFF)

add_library(hashids STATIC
  hashids.h hashids.cpp)

if(HASHID_BUILD_HASHIDSXX AND UNIX)
  add_executable(hashidsxx hashidsxx.cpp)
  target_link_libraries(hashidsxx hashids)
endif()

if(HASHID_BUILD_TESTS)
  enable_testing()
  file(MAKE_DIRECTORY thirdparty)
  file(DOWNLOAD
    "https://github.com/google/googletest/archive/release-1.7.0.zip"
    "thirdparty/gtest-1.7.0.zip"
    SHOW_PROGRESS
    STATUS status
    LOG log)
  # TODO: add tests, gtests
endif()
