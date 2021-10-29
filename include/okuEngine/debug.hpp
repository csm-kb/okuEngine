#ifndef OKUENGINE_DEBUG_H
#define OKUENGINE_DEBUG_H

#include <okuEngine/types.hpp>

namespace okuEngine {
    enum LogLevel {
        VERBOSE, DEBUG, ERR, WARN, INFO, NONE
    };

    class Debug final {
    public:    
        static const oMap<LogLevel,const char*> LogLevelToString;
        /**
         * @brief Writes a message at the specified log level to the log/stdout.
         * 
         * @param msg The message to write to log.
         * @param lvl The LogLevel to write at.
         */
        static void Log(const char* msg, LogLevel lvl = LogLevel::INFO, const char* endl = "\n");
        static void Log(oString msg, LogLevel lvl = LogLevel::INFO, const char* endl = "\n");
        static void SetLogLevel(LogLevel lvl);
    private:
        inline static LogLevel _writeLevel;
    };
}

#endif