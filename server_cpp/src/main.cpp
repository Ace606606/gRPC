#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "user.grpc.pb.h"

// using grpc::Server;
// using grpc::ServerBuilder;
// using grpc::ServerContext;
// using grpc::Status;
// using userapi::UserRequest;
// using userapi::UserReply;
// using userapi::UserService;

class UserServiceImpl final : public userapi::UserService::Service {
    public:
        grpc::Status GetUserInfo(grpc::ServerContext*,
                                const userapi::UserRequest* request,
                                userapi::UserReply* reply) override {
            std::string name = request->name();
            reply->set_greeting("Hello, " + name + " from C++ server!");
            return grpc::Status::OK;
        }
};

void RunServer() {
    std::string address("0.0.0.0:50051");
    UserServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listhening on " << address << std::endl;
    server->Wait();
    
}

int main() {
    RunServer();
    return 0;
}