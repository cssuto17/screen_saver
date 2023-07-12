#include "screen_holder.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>

ScreenHolder::ScreenHolder()
: _isStart(false)
{
}

void ScreenHolder::Start()
{
    cout << "Screen Holder Start. Enter 'q' to escape.\n";
    _isStart = true;
    if(_isStart)
    {
        _mouseEventWheelThread = thread([this](){
            MouseWheelEvent();
        });
        _isStartHandlerThread = thread([this](){
            IsStartHandler();
        });
        _mouseEventWheelThread.join();
        _isStartHandlerThread.join();
    }
}

void ScreenHolder::Stop()
{
    cout << "Screen Holder Stop.\n";
    _isStart = false;
}

void ScreenHolder::MouseWheelEvent()
{
    while (_isStart)
    {
        keybd_event(VK_F24, 0, 1, 0);
        cout<<"key called.\n";
        this_thread::sleep_for(chrono::seconds(299));
    }
}

void ScreenHolder::IsStartHandler()
{
    while(_isStart)
    {
        string shutDown = "";
        cin >> shutDown;
        if(shutDown == "q")
        {
            Stop();
        }
    }
}
