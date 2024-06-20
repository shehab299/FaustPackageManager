#pragma once

#include <exception>
#include <string>

class PkgUrlExcption : public std::exception
{
private:
    std::string message;
    
public:
    PkgUrlExcption(const std::string message_) : message(message_){}
        
    virtual const char* what() const noexcept override{
        return message.c_str();
    }
};
