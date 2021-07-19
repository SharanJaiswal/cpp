#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for( int x : values)
    {
        func(x);
    }
}

void EachFor(std::vector<int>& values, const std::function<void(int)>& func)
{
    for (int x : values)
    {
        func(x);
    }
}


int main()
{
    #include "../fileio.h"
    std::vector<int> values = {1, 2, 3, 4, 5};

    auto lambda1 = [](int x){ std::cout << "value : " << x << std::endl; };
    ForEach(values, lambda1);

    int a = 5, b = 3;
    auto lambda2 = [a, &b](int x){ std::cout << "Value : " << x << ", a : " << a << ", b : " << ++b << std::endl; };
    EachFor(values, lambda2);


    // below function is in algorithm header, looks for the first element that match in the iterator and returns the iterator of that first element
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
    std::cout << *it << std::endl;

    return 0;
}