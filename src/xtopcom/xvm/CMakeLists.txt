cmake_minimum_required(VERSION 3.8)
add_compile_options(-static -Wall -Werror)

if (XBUILD_TEST)
    add_definitions(-DXENABLE_TESTS)
endif()

if (DISABLE_REAL_STAKE)
    add_definitions(-DXENABLE_MOCK_ZEC_STAKE)
endif()
if (MAINNET_ACTIVATED)
    add_definitions(-DMAINNET_ACTIVATED)
endif()

if (STATIC_CONSENSUS)
    add_definitions(-DSTATIC_CONSENSUS)
endif()
if (ELECT_WHEREAFTER)
    add_definitions(-DELECT_WHEREAFTER)
endif()
if (CONSENSUS_SWAP)
    add_definitions(-DCONSENSUS_SWAP)
endif()

aux_source_directory(./ xvm)
aux_source_directory(./manager manager)
aux_source_directory(./xcontract xcontract)
aux_source_directory(./xserialization xserialization)
aux_source_directory(./xerror xerror)
aux_source_directory(./xsystem_contracts/deploy system_contracts_deploy)
aux_source_directory(./xsystem_contracts/src system_contracts_src)
aux_source_directory(./xsystem_contracts/xeth system_contracts_xeth)

add_library(xvm STATIC ${xvm} ${manager} ${xcontract} ${xserialization} ${xerror} ${system_contracts_deploy} ${system_contracts_src} ${system_contracts_xeth})

add_dependencies(xvm xstatestore xconfig xstore xverifier xdata xcommon xcodec xbasic xxbase xcertauth xchain_upgrade)

target_link_libraries(xvm PRIVATE xstatestore xconfig xevm_common xrouter xverifier xdata xcommon xcodec xbasic xstore xxbase protobuf lua xcertauth xchain_upgrade ethash keccak)

if (BUILD_METRICS)
    #add_dependencies(xvm xmetrics)
    target_link_libraries(xvm PRIVATE xmetrics)
endif()
