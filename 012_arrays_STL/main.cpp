// std::array are build in stack memory

#include <iostream>
#include <array>

int main()
{
    #include "../fileio.h"
    std::array<int, 5> arr1;
    for(int i = 0; i < arr1.size(); i++)
    {
        arr1[i] = i+3;
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << std::endl;
    }
    return 0;
}