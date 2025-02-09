#add_compile_options(-static -Wall -Werror)
add_compile_options(-static)

include_directories(.)
include_directories(./src)

aux_source_directory(./src src_dir)
add_library(xblockmaker STATIC ${src_dir})
IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_link_libraries(xblockmaker PRIVATE
        xtxpool_v2
        xtxexecutor
        xblockstore
        xstore
        xstatectx
        xstate_reset
        xverifier
        xvm
        xchain_upgrade
        xdata
        xxbase
        xcontract_vm
        xstate_mpt
    )
ELSE()
    target_link_libraries(xblockmaker PRIVATE
        xtxpool_v2
        xtxexecutor
        xblockstore
        xstore
        xstatectx
        xstate_reset
        xverifier
        xvm
        xchain_upgrade
        xdata
        xxbase
        intel_aes64
        xcontract_vm
        xstate_mpt
    )
ENDIF()

if (BUILD_METRICS)
    target_link_libraries(xblockmaker PRIVATE xmetrics)
endif()

