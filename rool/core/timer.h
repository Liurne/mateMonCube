#ifndef TIMER_H
#define TIMER_H

#include "include.h"

/**
 * @brief Class who manage timer to simplify SDL2 library
 * 
 */
class Timer
{
    private:
    //Time when the timer is started
    int startTicks;

    //Time when the time is paused
    int pausedTicks;

    //State of the timer
    bool paused;
    bool started;

    public:
    /**
     * @brief Construct a new Timer object wiith default value
     * 
     */
    Timer();

    /**
     * @brief Start timer
     * 
     */

    void start();
    /**
     * @brief Stop timer
     * 
     */
    void stop();
    /**
     * @brief Pause timer
     * 
     */
    void pause();
    /**
     * @brief unpauser timer
     * 
     */
    void unpause();

    /**
     * @brief Get the Ticks object
     * 
     * @return int the amount of milliseconds since the timer started
     * or return the amount of milliseconds since the timer is paused
     */
    int getTicks();

    /**
     * @brief Check if the timer has started
     * 
     * @return true it is started
     * @return false it is not started
     */
    bool isStarted();
    /**
     * @brief Check if the timer has paused
     * 
     * @return true it is paused
     * @return false it  is not paused
     */
    bool isPaused();
};


#endif