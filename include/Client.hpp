#pragma once
#include <string>
#include <string_view>
#include <unistd.h>
enum class STATE { WAITING, ACTIVE, DISCONNECTED };
class Client {
private:
  STATE ClientState = STATE::WAITING;
  std::string Address = "Unknown";
  std::string Username = "Unknown";
  unsigned id{}; // Might be usefull for multiple user with same name
  int fd{-1};
  /* future
    room id
    buffers
  */

public:
  Client(std::string_view add, std::string_view username, int fd)
      : Address(add), Username(username), fd(fd) {};
  ~Client(){closeClient();};
  Client(const Client&) = delete;
  Client& operator=(const Client&) = delete;
  Client(Client&&) = delete;
  Client& operator=(Client&&) = delete;
  const std::string& getUsername() const { return Username; }
  const unsigned& getID() const { return id; }
  const std::string& getAddress() const { return Address; }
  const int& getFD() const {return fd;}
  void closeClient();
};