#include <okuEngine/debug.hpp>
#include <iostream>

namespace okuEngine {
    const oMap<LogLevel,const char*> Debug::LogLevelToString = {
        {LogLevel::VERBOSE, "VBSE"}, {LogLevel::DEBUG, "DBUG"},
        {LogLevel::ERR, "WERR"}, {LogLevel::WARN, "WARN"}, {LogLevel::INFO, "INFO"}
    };

    void Debug::Log(const char* msg, LogLevel lvl, const char* endl) {
        // TODO: possibly write to output file of some kind
        if (_writeLevel <= lvl) {
            std::cout << "[" << LogLevelToString.at(lvl) << "]\t " << msg << endl;
        }
    }
    void Debug::Log(oString msg, LogLevel lvl, const char* endl) {
        Log(msg.c_str(), lvl, endl);
    }

    void Debug::SetLogLevel(LogLevel lvl) { _writeLevel = lvl; }
}
