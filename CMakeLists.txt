cmake_minimum_required(VERSION 3.0.0)
project(network_protocol_stack_cpp VERSION 0.1.0)

# include(CTest)
# enable_testing()
# add_library(pcap_lib STATIC 
#     ${PROJECT_SOURCE_DIR}/lib/xnet/pcap_device.cpp
# )

file(GLOB_RECURSE CPP_SOURCE
        ${PROJECT_SOURCE_DIR}/src/app/*.cpp
        ${PROJECT_SOURCE_DIR}/src/network/*.cpp
)

# file(GLOB_RECURSE HEADER_SOURCE
#         # ${PROJECT_SOURCE_DIR}/src/include/network/*.h
#         ${PROJECT_SOURCE_DIR}/src/include
# )

set(SOURCES
    ${PROJECT_SOURCE_DIR}/lib/xnet/pcap_device.cpp
    # ${PROJECT_SOURCE_DIR}/src/app/port_pcap.cpp

    # ${PROJECT_SOURCE_DIR}/lib/xnet/enc28j60_device.cpp
    # ${PROJECT_SOURCE_DIR}/src/network/xnet_tiny.cpp
    # ${PROJECT_SOURCE_DIR}/src/network/Hello.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${CPP_SOURCE}
)



add_executable(${PROJECT_NAME} ${SOURCES})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/npcap/Include
        ${PROJECT_SOURCE_DIR}/lib/xnet
        ${PROJECT_SOURCE_DIR}/src/include
        # ${HEADER_SOURCE}
)

# link_libraries(${PROJECT_NAME} ws2_32)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        # ${PROJECT_SOURCE_DIR}/lib/wpcap.dll
        # ${PROJECT_SOURCE_DIR}/lib/Packet.dll    
        ${PROJECT_SOURCE_DIR}/lib/libws2_32.a
        ${PROJECT_SOURCE_DIR}/lib/npcap/Lib/x64/Packet.lib
        ${PROJECT_SOURCE_DIR}/lib/npcap/Lib/x64/wpcap.lib
)