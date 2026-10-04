#include "../include/Client.hpp"
#include <cstdint>
#include <unistd.h>
#include <random>
void Client::closeClient()
{
    fd.closeFD();
    ClientState = STATE::OFFLINE;
}
uint16_t Client::generateID(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 65535); 
    
    return static_cast<uint16_t>(distrib(gen));
}
