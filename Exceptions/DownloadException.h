#include <exception>
#include <string>


class DownloadException : public std::exception
{
private:
    std::string message;
public:
    DownloadException(std::string message_) : message(message_)
    {}

    virtual const char* what() const noexcept{
        return message.c_str();
    }
};

