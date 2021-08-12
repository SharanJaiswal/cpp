// doubly ended queue DEQUE (pronounced as "DECK"); implemented via various static array and hence book-keeping
// It is dynamic in nature. NOT TELLING THAT ITS IMPLEMENTED ON DYNAMIC MEMORY
#include <iostream>
#include <deque>

int main()
{
    #include "../fileio.h"
    std::deque<int> d(10);
    // if we will not give the (), then starting spaces will be 0, and it will increase the capacity of it
    // It does not restrict the capacity of the deque. If 11th element is inserted, new static array will be initialized
    
    d.push_back(1);
    d.push_front(2);
    d.emplace_back(3);
    d.emplace_front(4);

    for(int element : d)
    {
        std::cout << element << ", ";
    } std::cout << std::endl;

    std::cout << d.size() << std::endl;
    d.pop_back();
    d.pop_front();
    std::cout << d.size() << " " << d.front() << " " << d.at(0) << " " << d.back() << " " << d.at(1) <<  std::endl;

    std::cout << d.empty() << std::endl;

    d.erase(d.begin());
    std::cout << d.size() << std::endl;
    d.push_back(1);
    d.push_front(2);
    d.emplace_back(3);
    d.emplace_front(4);
    // 4 2 1 1 3
    d.erase(d.begin(), d.begin()+2);    // removes element 4 & 2
    for(int ele : d)
    {
        std::cout << ele << " ";
    } std::cout << "\n";

    std::cout << d.max_size() << std::endl;

    // front back begin* end* erase insert size resize shrink_to_fit clear empty = [] (basically same as vector along with push|emplace|pop_front)

    return 0;
}