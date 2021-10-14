#ifndef OKUENGINE_TIME_H
#define OKUENGINE_TIME_H

namespace okuEngine {
    class Time final {
    public:
        /** @brief The interval in seconds from the last frame to the current one. */    
        inline static double deltaTime = 0.016;
        /** @brief The interval in seconds at which physics and other fixed frame rate updates are performed. */
        inline static double fixedDeltaTime = 0.02;
    private:
        Time();
    }
}

#endif