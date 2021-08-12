#include <iostream>
#include <string>
// #include <utility> // here pair is defined, but not  necessary to define it explicitly. iostream will do the work

int main()
{
    #include "../fileio.h"

    std::pair<int, int> duo;        // ={1,2}; or, std::par<int, int> duo(1,2);
    duo = {3, 4};
    std::cout << duo.first << ", " << duo.second << std::endl;
    std::pair<int, int> duo2;   // duo2(duo); or, duo2 = duo;   // copying constructor and assignment operator
    // duo2 = duo; // assignment is possible in pair
    

    // similarly, copying and comparision is also possible

    std::pair<int, std::pair< int, std::string> > nest;     // ={3, {4, std::string("Sharan")}};
    // nest = {3, {4, std::string("Sharan")}};
    nest.first = 5;
    nest.second.first = 6;              // nest.second = {6, "jaiswal"} or, {6, std::string("Jaiswal")};
    nest.second.second = std::string("Jaiswal");    // nest.second.second = "Jaiswal"

    std::pair<int, int> arr[]= {{1,2}, {3,4}, {5,6}};
    std::cout << arr[1].second << std::endl;

// make_pair(val, val2) ==> this will construct pair and then can be used

// =, ==, !=, >=, <= are also implicitly overloaded for pair

bool val = duo < duo2;
std::cout << val << std::endl;

    return 0;
}