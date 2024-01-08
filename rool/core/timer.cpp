#include "timer.h"

//Constructor
Timer::Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

//Start the timer
void Timer::start()
{
    started = true;
    paused = false;

    startTicks = SDL_GetTicks();
}

//Stop the timer
void Timer::stop()
{
    started = false;
    paused = false;
}

//get the amount of milliseconds since the timer started or since he's paused
int Timer::getTicks()
{
    if( started == true )
    {
        if( paused == true )
        {
            return pausedTicks;
        }
        else
        {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

//pause the timer
void Timer::pause()
{
    if( ( started == true ) && ( paused == false ) )
    {
        paused = true;

        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

//unpause the timer
void Timer::unpause()
{
    if( paused == true )
    {
        paused = false;

        startTicks = SDL_GetTicks() - pausedTicks;

        pausedTicks = 0;
    }
}

bool Timer::isStarted()
{
    return started;
}

bool Timer::isPaused()
{
    return paused;
}