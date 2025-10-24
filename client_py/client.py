import grpc
import user_pb2
import user_pb2_grpc

def run():
    channel = grpc.insecure_channel("localhost:50051")
    stub = user_pb2_grpc.UserServiceStub(channel)

    responce = stub.GetUserInfo(user_pb2.UserRequest(name="Test"))
    print("Responce:", responce.greeting)

if __name__ == "__main__":
    run()