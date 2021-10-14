#include <okuEngine/debug.hpp>
#include <iostream>

const std::map<okuEngine::LogLevel,const char*> okuEngine::Debug::LogLevelToString = {
    {LogLevel::VERBOSE, "VBSE"}, {LogLevel::DEBUG, "DBUG"},
    {LogLevel::ERR, "WERR"}, {LogLevel::WARN, "WARN"}, {LogLevel::INFO, "INFO"}
};

void okuEngine::Debug::Log(const char* msg, LogLevel lvl) {
    // TODO: possibly write to output file of some kind
    if (_writeLevel <= lvl) {
        std::cout << "[" << LogLevelToString.at(lvl) << "]\t " << msg << std::endl;
    }
}
void okuEngine::Debug::Log(std::string msg, LogLevel lvl) { Log(msg.c_str(), lvl); }

void okuEngine::Debug::SetLogLevel(LogLevel lvl) { _writeLevel = lvl; }