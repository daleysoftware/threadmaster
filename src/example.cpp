#include <iostream>

#include "Thread.h"
#include "GetTime.h"
#include "Delay.h"

class ExampleThread : public ThreadMaster::Thread
{
    void Run(void* ptr)
    {
        while(!IsStopped())
        {
            std::cout << "Running..." << std::endl;
            m_signal.WaitSignal(1000);
        }
    }
};

int main()
{
    std::cout << "Program will run for 5 seconds." << std::endl;

    ExampleThread et;
    et.Start();
    ThreadMaster::Delay::Milli(5*1000);
    et.Stop();
    return 0;
}
