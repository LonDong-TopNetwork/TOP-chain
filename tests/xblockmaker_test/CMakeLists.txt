#add_compile_options(-static -Wall -Werror)
add_compile_options(-static)


aux_source_directory(./ test_dir)
add_executable(xblockmaker_test ${test_dir})

# add_dependencies(xblockmaker_test xblockmaker)
# include_directories(src/xtopcom/xblockstore/)
target_link_libraries(xblockmaker_test PRIVATE
    xblockmaker
    xblockstore xtxstore xdbstore
    xvm xcertauth xvnetwork xchain_upgrade xdata xloader xgenesis
    gtest
)
