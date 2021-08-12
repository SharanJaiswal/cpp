// List are implemented using DLL, having two pointers and one data node
// Direct access to the particular node is not allowed; traversing should be done for the same

#include <iostream>
#include <list>

int main()
{
    #include "../fileio.h"
    std::list<int> L;   // initialization and copy also possible
    L.emplace_back(1);  // push_back pop_back pop_front
    L.emplace_front(2);
    for(int x : L)
    {
        std::cout << x << ", ";
    } std::cout << std::endl;

    // L.erase(L.begin()+1, L.begin()+2);   // not possible because its not allowed to do iterator arithmetic inside of the ()
    L.erase(L.begin(), L.end());    // this will work fine; returns the itr pointing to the next of the last element actually deleted
    auto itr1 = L.begin();
    itr1 = itr1++;  // only this type of arithmetic is allowed. Not even normal arithmetic is allowed

    // advance
    std::advance(itr1, 3);  // by this way, one can increase the iterator value where arithmetic is not allowed
    // also, for bi-di iterators, value can be -ve. ege, advance(itr, -6);
    // we can now use this in erase, insert, etc. 

    L.emplace_back(10);
    L.emplace_back(1);
    L.emplace_back(16);
    L.emplace_back(3);
    L.emplace_back(56);
    L.emplace_back(-2);
    L.emplace_back(5);
    L.emplace_back(-2);

    // Sorting
    L.sort();
    // std::sort(L.begin(), L.end());   // For list, or for any non-contiguous DS STL, std::sort() will NOT work.
    for(int x : L)
    {
        std::cout << x << ", ";
    } std::cout << std::endl;

    // Reversing
    L.reverse();
    for(int x : L)
    {
        std::cout << x << ", ";
    } std::cout << std::endl;

    // Insert: parameters: 1st-position; 2nd(optional if single element is inserted, where element is 3rd element)
    // or, 2nd and 3rd will be starting and ending(excluded) itr of the origin iterable
    // or, only 2nd no 3rd; where 2nd itself will be the actual iterator
    std::list<int>::iterator it = L.begin();
    std::advance(it, 2);
    L.insert(it, 2, 7);
    for (std::list<int>::iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
    // Unlike vectors, or any contiguous DS STL, the iterators after insert and erase, etc, still points to the same node where they were poiniting initially



    // .remove(value) takes the value of the node and delets all occurences of that value on the list. It'll throw error of value not found in list
    // .remove_if(bool value through predicate returning bool value)
    L.remove_if([](int &num) { return num%2==0; });
    for (std::list<int>::iterator i = L.begin(); i != L.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    // [SORTED] .unique()
    // [SORTED] dest_list.merge(Sec_list [, predicate] ) // in ASC order


    // begin end rbegin cbegin crbegin rend cend crend ======= front back
    // empty size resize(count [, val])
    return 0;
}