#pragma once
#include "Client.hpp"
#include <unordered_map>
class Server {

    private:
        std::unordered_map<unsigned, Client>clients;
        std::unordered_map<int, unsigned>connected;
    public:
        Server(){}
        void init();
        void listenConnection();
        void run();
        int addClient(const Client& client);


};