#include <iostream>
#include <thread>

static bool s_flag = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;
    // some thread func work
    while(!s_flag)
    {
        std::cout << "[Working...!]" << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    #include "../fileio.h"

    std::thread worker(DoWork);

    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(6s);
    s_flag = true;

    worker.join();
    std::cout << "[Fin...]" << std::endl;

    return 0;
}