# CMake script for JetConf experiments: customer_conf

# customer lib
set(CUSTOMER_LIB "customer_conf")
add_library(${CUSTOMER_LIB} SHARED)
target_sources(${CUSTOMER_LIB} PRIVATE
        customer_conf.h
        customer_conf.cpp
        )
target_link_libraries(${CUSTOMER_LIB} PRIVATE jsoncpp_lib)

# customer test
set(CUSTOMER_TEST "customer_test")
add_executable(${CUSTOMER_TEST})
target_sources(${CUSTOMER_TEST} PRIVATE
        customer_conf_test.cpp
        )
target_link_libraries(${CUSTOMER_TEST} PRIVATE customer_conf gtest gtest_main)

