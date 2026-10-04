#pragma once
#include <unistd.h>
#include <utility>
class Filedescriptor{
    private:
        int fd{-1};
    public:
        explicit Filedescriptor(int fd) :fd(fd) {}
        ~Filedescriptor(){
            closeFD();
        } 
        Filedescriptor()  = default;
        Filedescriptor(const Filedescriptor&) = delete;
        Filedescriptor& operator=(const Filedescriptor&) = delete;
        Filedescriptor (Filedescriptor&& o) noexcept : fd(std::exchange(o.fd, -1)) {}
        Filedescriptor& operator =(Filedescriptor&& o) noexcept
        {
            if (this != &o) {
                closeFD();
                fd = std::exchange(o.fd, -1);
            }
            return *this;
        }
       bool isValid() const{return fd != -1;}
       explicit operator bool() const{return isValid();}
       int getFD() const {return fd;}
       void closeFD(){
            if (fd != -1) {
                close(fd);
                fd =-1;
            }
    } 
};