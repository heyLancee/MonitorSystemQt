#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>
#include "base.h"

class TcpClient {
public:
    TcpClient(const std::string& host, int port, double T, double Ts)
        : host(host), port(port), T(T), Ts(Ts) {}

    bool connectToServer() {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            std::cerr << "Error creating socket" << std::endl;
            return false;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, host.c_str(), &server_addr.sin_addr) <= 0) {
            std::cerr << "Invalid address/ Address not supported" << std::endl;
            return false;
        }

        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Connection Failed" << std::endl;
            return false;
        }

        std::cout << "Connected to server" << std::endl;
        return true;
    }

    void sendData() {
        double elapsedTime = 0;
        telemetryStruct data;

        // 示例帧头和帧尾
        std::string frameHead = "SSSSSSSS";
        std::string frameTail = "EEEEEEEE";

        CommuDataType dataType = CommuDataType::telemetryType;

        while (elapsedTime < T) {
            data.timeStep = elapsedTime;
            data.wx = 3.0f + elapsedTime; // 示例数据
            data.wy = 4.0f + elapsedTime;
            data.wz = 5.0f + elapsedTime;

            // 将数据转换为字节数组
            QByteArray byteArray = data.toByteArray();

            // 添加帧头、类型、数据和帧尾
            QByteArray packet;
            packet.append(frameHead.c_str());
            packet.append(static_cast<char>(dataType));
            packet.append(byteArray);
            packet.append(frameTail.c_str());

            send(sockfd, packet.data(), packet.size(), 0);
            std::cout << "Sent telemetry data at time: " << elapsedTime << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(Ts * 1000)));
            elapsedTime += Ts;
        }
    }

    ~TcpClient() {
        close(sockfd);
    }

private:
    int sockfd;
    struct sockaddr_in server_addr;
    std::string host;
    int port;
    double T;  // 总时间长度
    double Ts; // 周期
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << "<Port> <T> <Ts>" << std::endl;
        return 1;
    }
    // 从命令行参数中读取
    int port;
    double T, Ts;

    try {
        port = std::stoi(argv[1]);
        T = std::stod(argv[2]);
        Ts = std::stod(argv[3]);
    } catch (const std::exception& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    }

    TcpClient client("127.0.0.1", port, T, Ts);
    if (client.connectToServer()) {
        client.sendData();
    }
    return 0;
}