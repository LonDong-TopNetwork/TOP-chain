cmake_minimum_required(VERSION 3.8)

add_compile_options(-Wpedantic)

aux_source_directory(./src safebox_test_src)

add_executable(xsafebox_test ${safebox_test_src})

target_include_directories(xsafebox_test PRIVATE ${CMAKE_SOURCE_DIR}/src/xtopcom/xdepends/openssl_include/openssl/)

target_link_libraries(xsafebox_test PRIVATE xsafebox xmutisig xhttp xbasic gtest gtest_main pthread)