#include <iostream>
#include <set>
// All the elements stored in the set are unique. Even if we insert same element multiple times, the element wiil stored once inside of the set
// Modifiction of the elements inside of the set is not allowed. Either insert or pop. THATS IT
// Ordered set uses BST BTS. unordered_set uses array and hash map.
// In ordered ser, elements are popped in sorted order; while in unordered_set, elemnts are popped out in random manner

int main()
{
    #include "../fileio.h"
    
    std::set<int> OS;
    OS.insert(5);
    OS.insert(5);
    OS.insert(1);
    OS.insert(1);
    OS.insert(6);
    OS.insert(6);
    OS.insert(6);
    OS.insert(0);
    OS.insert(0);
    OS.insert(0);

    for( int x : OS)    // vene if smae element is inserted multiple times, the element appears only once in the set
    {
        std::cout << x << " ";
    } std::cout << std::endl;

    auto itr = OS.find(1);
    if(itr == OS.end())
    {
        std::cout << "Not present" << std::endl;
    }
    else
    {
        std::cout << "Present" << std::endl;
    }

    std::set<int>::const_iterator itr_str = OS.begin();
    std::set<int>::const_iterator itr_end = itr_str++;  // here, iterartor arithmetic wont work
    OS.erase(itr_str, itr_end);
      

    return 0;
}