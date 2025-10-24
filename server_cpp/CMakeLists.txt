cmake_minimum_required(VERSION 3.15)
project(grpc_cpp_server)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_executable(server
    src/main.cpp
    src/user.pb.cc
    src/user.grpc.pb.cc
)

target_include_directories(server PRIVATE ${Protobuf_INCLUDE_DIRS} src)
target_link_libraries(server PRIVATE gRPC::grpc++ ${Protobuf_LIBRARIES})
