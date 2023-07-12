#pragma once

#include <thread>
#include <shared_mutex>

using namespace std;

class ScreenHolder
{
    public:
    ScreenHolder();
    void Start();
    void Stop();
    void MouseWheelEvent();
    void IsStartHandler();

    private:
    shared_mutex _screenHolderSharedMutex;
    thread _mouseEventWheelThread;
    thread _isStartHandlerThread;
    bool _isStart;
};