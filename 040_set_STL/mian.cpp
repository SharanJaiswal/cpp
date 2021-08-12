#include <iostream>
#include <set>  // includes ordered set, multiordered set, BUT NOT UNORDERED SET
#include <unordered_set>    // include unordered_set and unordered_multiset
// All the elements stored in the set are unique. Even if we insert same element multiple times, the element will stored once inside of the set
// Modifiction of the elements inside of the set is not allowed. Either insert or pop. THATS IT
// Ordered set uses BST BTS. unordered_set uses array and hash map.
// In ordered ser, elements are popped in sorted order; while in unordered_set, elemnts are popped out in random manner

int main()
{
    #include "../fileio.h"
    
    std::set<int> OS;
    OS.insert(5);
    OS.insert(5);
    OS.emplace(1);
    OS.insert(1);
    OS.insert(6);
    OS.emplace(6);
    OS.insert(6);
    OS.emplace(0);
    OS.insert(0);
    OS.emplace(0);

    for( int x : OS)    // even if same element is inserted multiple times, the element appears only once in the set
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
    OS.erase(itr_str, itr_end); // [start, end)

    OS.erase(6);    // .erase() of SET can also takes the key value to eleted it, because keys are unique in the set
    
    /* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
     = = = = = = = = = = = = = = = = = = = = = = M U L T I S E T = = = = = = = = = = = = = = = = = = = = = =
     = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
    // in multiset, elements are stored in order. Hence, ordering or implicit sorting is present

     std::multiset<int> MS;
     MS.insert(1);  // 1
     MS.emplace(1); // 1, 1
     MS.insert(1);  // 1, 1, 1
     MS.emplace(2); // 1, 1, 1, 2

     MS.erase(1);   // 2    (deletes all the keys of the same value)

     MS.insert(1);  // 1, 2
     MS.emplace(1); // 1, 1, 2
     MS.insert(1);  // 1, 1, 1, 2
     MS.emplace(2); // 1, 1, 1, 2, 2

     MS.erase(MS.begin());
     MS.erase(MS.begin(), MS.end());    // iterator arithmetic not allowed

     MS.insert(1);  // 1
     MS.emplace(1); // 1, 1
     MS.insert(1);  // 1, 1, 1
     MS.emplace(2); // 1, 1, 1, 2
     // to delete the first occurence of the multi-occured element
     MS.erase(MS.find(1));  // since find() will return the itr to the first occurence of the key; that itr will be used in erase()

     /* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
     = = = = = = = = = = = = = = = = = = = = U N O R D E R E D - S E T = = = = = = = = = = = = = = = = = = =
     = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */

    // stores unique elements
    // not in sorted order
    // upper and lower_bound DOESNOT work
    // uses hash to store the elements. Collisions may happen

     return 0;
}