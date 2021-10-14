#ifndef OKUENGINE_EXCEPTIONS_H
#define OKUENGINE_EXCEPTIONS_H

#include <string>
#include <exception>

namespace okuEngine {
	/**
	 * @brief Exception thrown when ServiceLocator doesn't have a service bound for the specified type.
	 */
    class ServiceNotBoundException : public std::exception {
	private:
        static std::string make_message(int code, const std::string& source, const std::string& message);
    	std::string message;

    public:
        ServiceNotBoundException();
    	explicit ServiceNotBoundException(const std::string& message);
    	ServiceNotBoundException(const std::string& source, const std::string& message);
    	ServiceNotBoundException(int code, const std::string& source, const std::string& message);
    	const char *what() const throw();
    };
}

#endif