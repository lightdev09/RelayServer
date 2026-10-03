#pragma once
#include <sys/socket.h>
namespace Config {
    constexpr int SOCKETTYPE = SOCK_STREAM;
    constexpr int PORT = 3000;
    constexpr int ADD_FAMILY = AF_UNSPEC;
    constexpr int LISTEN_BACKLOG = 10;
    constexpr int MAX_USERNAME_LENGTH = 64;
    constexpr int MAX_MSG_LEN = 1024;
    constexpr int RECV_BUFFR_LEN = 1024;
    constexpr int MAX_CLIENTS =20;
    constexpr int MAX_PENDING = 10;
    constexpr int PENDING_TIMEOUT_MS = 1000;
    constexpr int POLL_TIMEOUT_MS = -1;
}