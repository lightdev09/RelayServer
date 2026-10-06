#pragma once
#include "Client.hpp"
#include "Filedescriptor.hpp"
#include <cstdint>
#include <unordered_map>
#include <chrono>
struct PendingConn {
    Filedescriptor fd;
    std::string address, username, recvBuffer;
    std::chrono::steady_clock::time_point since;
};
class Server {

    private:
    Filedescriptor listningFD{-1};
        std::unordered_map<unsigned, Client>clients;
        std::unordered_map<int, unsigned>connected;
        std::unordered_map<int, PendingConn>pending;
        uint16_t generateID();
        void listenConnection();
        void disconnect();
    public:
        Server(){}
        void run();
        int addClient(const Client& client);


};