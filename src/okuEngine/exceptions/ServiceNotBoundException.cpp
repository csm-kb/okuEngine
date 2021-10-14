#include <okuEngine/exceptions.hpp>
#include <iostream>
#include <sstream>

namespace okuEngine{
    ServiceNotBoundException::ServiceNotBoundException() :
        ServiceNotBoundException(0, "No source.", "No message.") {}

    ServiceNotBoundException::ServiceNotBoundException(const std::string& message) :
        ServiceNotBoundException(0, "No source.", std::move(message)) {}

    ServiceNotBoundException::ServiceNotBoundException(const std::string& source, const std::string& message) :
        ServiceNotBoundException(0, std::move(source), std::move(message)) {}

    ServiceNotBoundException::ServiceNotBoundException(int code, const std::string& source, const std::string& message) :
        message(make_message(code, source, message))
    {}

    const char *ServiceNotBoundException::what() const throw()
    {
        return message.c_str();
    }

    std::string ServiceNotBoundException::make_message(int code, const std::string& source, const std::string& message)
    {
        std::stringstream s;
        s << "ServiceNotBoundException Data:" << std::endl;
        s << "Code    : " << code << std::endl;
        s << "Source  : " << source << std::endl;
        s << "Message : " << message << std::endl;

        // takes a copy, returns a copy - safe!
        return s.str();
    }
}