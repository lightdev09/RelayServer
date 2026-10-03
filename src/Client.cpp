#include "../include/Client.hpp"
#include <unistd.h>

void Client::closeClient()
{
    if (fd != -1) {
        close(fd);
        fd = -1;
    }
    ClientState = STATE::OFFLINE;
}