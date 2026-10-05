#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include "Filedescriptor.hpp"
class Client {
private:
  std::string Address = "Unknown";
  std::string Username = "Unknown";
  uint16_t id{}; // Might be usefull for multiple user with same name
  Filedescriptor fd{};
  /* future
    room id
    buffers
  */

public:
  Client(std::string_view add, std::string_view username,uint16_t cid, int cfd)
      : Address(add), Username(username),id(cid), fd(cfd) {}
  ~Client(){closeClient();};
  // Screw all copy constructors
  Client(const Client&) = delete;
  Client& operator=(const Client&) = delete;
  Client(Client&&) = delete;
  Client& operator=(Client&&) = delete;
  const std::string& getUsername() const { return Username; }
  uint16_t getID() const { return id; }
  const std::string& getAddress() const { return Address; }
  int getFD() const {return fd.getFD();}
  void closeClient();
  uint16_t generateID();
};