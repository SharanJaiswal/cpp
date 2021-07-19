// std::array are build in stack memory

#include <iostream>
#include <array>

template<typename T, int size>  // Taking std array as aparameter using  template
void Printarr(std::array<T, size>& arr1)
{
    for(T x : arr1)   // Range based for loop ////// for-each loop
    {
        std::cout << x << std::endl;
    }
}

int main()
{
    #include "../fileio.h"
    std::array<int, 5> arr1;    // = {1,2,3,4,5}
    for(int i = 0; i < arr1.size(); i++)
    {
        arr1.at(i) = i+1;   // arr1[i] = i+1;
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << std::endl;
    }
    Printarr<int, 5>(arr1);

    // return boolean value for checking if the array is empty or not
    std::cout << "Is empty? " << arr1.empty() << std::endl;

    // accessing first and last element directly using array methods
    std::cout << "first: " << arr1.front() << ", " << *arr1.begin() << std::endl << "Last: " << *arr1.end() << ". " << arr1.back() << ", " << std::endl;

    return 0;
}