// List are implemented using DLL, having two pointers and one data node
// Direct access to the particular node is not allowed; traversing should be done for the same

#include <iostream>
#include <list>

int main()
{
    #include "../fileio.h"
    std::list<int> L;
    L.emplace_back(1);
    L.emplace_front(2);
    for(int x : L)
    {
        std::cout << x << ", ";
    } std::cout << std::endl;

// begin end empty back front pop_back pop_front size max_size

// initialization and copy also possible


    return 0;
}