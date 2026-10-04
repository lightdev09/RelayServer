#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include "Filedescriptor.hpp"
enum class STATE { ONLINE, OFFLINE };
class Client {
private:
  STATE ClientState = STATE::OFFLINE;
  std::string Address = "Unknown";
  std::string Username = "Unknown";
  unsigned id{}; // Might be usefull for multiple user with same name
  Filedescriptor fd{};
  /* future
    room id
    buffers
  */

public:
  Client(std::string_view add, std::string_view username, int cfd)
      : Address(add), Username(username), fd(cfd) {id = static_cast<unsigned>(generateID());}
  ~Client(){closeClient();};
  // Screw all copy constructors
  Client(const Client&) = delete;
  Client& operator=(const Client&) = delete;
  Client(Client&&) = delete;
  Client& operator=(Client&&) = delete;
  const std::string& getUsername() const { return Username; }
  const unsigned& getID() const { return id; }
  const std::string& getAddress() const { return Address; }
  int getFD() const {return fd.getFD();}
  void closeClient();
  uint16_t generateID();
};