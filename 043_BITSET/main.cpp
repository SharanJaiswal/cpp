#include <iostream>
#include <bitset>

int main()
{
    #include "../fileio.h"
    std::bitset<5> bt1; // max 5 bits
    std::bitset<5> bt2(20); // maximum 5 bits where 20 is stored in bit-form
    std::bitset<4> bt3(std::string("1011"));    // ANOTHER ONE!

    std::cout << bt1 << ", " << bt2 << std::endl;
    bt1 = 11;   // assigning decimal number which implicitly gets converted to bit-form
    std::cout << bt1 << ", " << bt2 << std::endl;

    std::cin >> bt1;    // direct input will always be in bit form
    std::cout << bt1 << ", " << bt2 << std::endl;

    // [] ^ | & ~ ^= |= &= == != <<= >>=
    // bt.count()   gives number of set bits
    // bt.size()    gives the number required to initialize this bt variable, set and unset
    // bt.test(<index>) // returns true for 1 or false for 0
    // bt.any()|all()   // returns bool for performing checks for 1
    // bt.none()        // returns bool for performing check for 0. true if all are 0
    // bt.set()     // sets all bits to 1
    // bt.set(pos [, 0|1]) // sets bit at "pos" to (1, by defalut, or to) 1|0 if bit value is also specifed
    // bt.reset()   // sets all bits to 0
    // bt.reset(pos)    // sets pos bit to 0
    // bt.flip([pos])   // flips all  buts by defalut, if no specific position is specified
    // bt.to_ulong()    // to unsigned long
    // bt.to_ullong()   // to unsigned long long


    return 0;
}