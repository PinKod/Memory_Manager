cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_INIT "-Wall -Wextra -Wpedantic")

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_compile_options(-D_XOPEN_SOURCE=600)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_compile_options(-D_POSIX_C_SOURCE=199309L)
endif()

#add_executable(test1 tests/src/test1.c src/faults_handle.c src/cust_allocation.c src/include/extern_memery_manager.c)
add_executable(test2 tests/src/test2.c src/faults_handle.c src/cust_allocation.c src/include/extern_memery_manager.c)
#add_executable(test3 tests/src/test3.c src/faults_handle.c src/cust_allocation.c src/include/extern_memery_manager.c)



enable_testing()
#add_test(NAME test1 COMMAND ${CMAKE_COMMAND} -E run ${CMAKE_BINARY_DIR}/test1)
add_test(NAME test2 COMMAND ${CMAKE_COMMAND} -E run ${CMAKE_BINARY_DIR}/test2)
#add_test(NAME test3 COMMAND ${CMAKE_COMMAND} -E run ${CMAKE_BINARY_DIR}/test3)
