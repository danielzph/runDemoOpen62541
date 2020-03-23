cmake_minimum_required(VERSION 3.5)

project(demoOpen62541)

set (EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin) #生成可执行文件的位置

add_definitions(-std=c99)

include_directories(${PROJECT_SOURCE_DIR}/open62541)   #头文件的位置

link_directories(${PROJECT_SOURCE_DIR}/open62541/bin)  #库文件的位置

add_executable(server ${PROJECT_SOURCE_DIR}/src/server.c)
target_link_libraries(server libopen62541.a)

add_executable(client ${PROJECT_SOURCE_DIR}/src/client.c)
target_link_libraries(client libopen62541.a)

add_executable(server_one ${PROJECT_SOURCE_DIR}/src/server_one.c)
target_link_libraries(server_one libopen62541.a)

add_executable(client_one ${PROJECT_SOURCE_DIR}/src/client_one.c)
target_link_libraries(client_one libopen62541.a)

add_executable(client_test ${PROJECT_SOURCE_DIR}/src/client_test.c)
target_link_libraries(client_test libopen62541.a)

add_executable(client_test2 ${PROJECT_SOURCE_DIR}/src/client_test2.c)
target_link_libraries(client_test2 libopen62541.a)

add_executable(client_test3 ${PROJECT_SOURCE_DIR}/src/client_test3.c)
target_link_libraries(client_test3 libopen62541.a)






