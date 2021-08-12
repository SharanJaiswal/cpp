// std::array are build in stack memory

#include <iostream>
#include <array>

template<typename T, size_t size>  // Taking std array as a parameter using  template
void Printarr(std::array<T, size>& arr1)
{
    for(T x : arr1)   // Range based for loop ////// for-each loop
    {
        std::cout << x <<" ";
    } std::cout << std::endl;
}

int main()
{
    #include "../fileio.h"
    std::array<int, 5> arr1;    // or, = {1,2,3,4,5} // memory is initialized with some random garbage values
    // below two lines are used to demostrate that arrays are fully filled once theyare created, even by garbage values
    std::cout << "Is empty? " << arr1.empty() << std::endl;
    std::cout << arr1.size() << std::endl;

    // below is okay, will work fine. But lets see if range based for loop works for input or not
    // for(int i = 0; i < arr1.size(); i++)
    // {
    //     arr1.at(i) = i+1;   // arr1[i] = i+1;
    // }
    for(int &x : arr1)
    {
        std::cin >> x;
    }

    for (int i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    Printarr(arr1);

    // front back empty fill size swap %begin %end

    // return boolean value for checking if the array is empty or not
    std::cout << "Is empty? " << arr1.empty() << std::endl;

    // accessing first and last element directly using array methods
    std::cout << "first: " << arr1.front() << ", " << *arr1.begin() << std::endl << "Last: " << *(arr1.end()-1) << ", " << arr1.back() << ", " << std::endl;

    return 0;
}