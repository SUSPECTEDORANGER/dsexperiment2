cmake_minimum_required(VERSION 3.0.0)
project(DSexperiment2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DSexperiment2 
testDSexperiment2.c
DSexperiment2.c
DSexperiment2.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
