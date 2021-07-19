// They are basically used to assign function to the variables, which later can be used as variables, or passes to another function, etc.
#include <iostream>
#include <vector>

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

void Dummy(int n)
{
    std::cout << "Dummy Val : " << n << std::endl;
}

void PrintVal(int x)
{
    std::cout << " From func, Value : " << x << std::endl;
}

void ForEach(std::vector<int>& values, void(*func)(int))
{
    for(int x : values)
    {
        func(x);
    }
}

int main()
{
    #include "../fileio.h"
    HelloWorld();

    auto Function = HelloWorld;    // find this function's instruction address in binaries after compilation, in the mem loc, and return it.
    //Although there will be &HelloWorld,ie, a function pointer is returned in RHS, but implicit conversion is taking care of it.
    // Hover over the 'Function' variable, and see the type of it.
    // void(*Function)() = HelloWorld;  , or,
    // void(*Function)(); Function = HelloWorld;

    // Below is how we call the original function using 'Function'
    Function();
    Function();

    // We can use typedef also
    typedef void(*Alias)();
    Alias Func1 = HelloWorld;
    Func1();
    // Alias(); // Useless thing

    // calling another function
    typedef void(*Alia)(int);
    Alia func2 = Dummy;
    func2(1);
    func2(2);
    // Useless thing below 2
    // Alia(3);
    // Alia(4);


    std::vector<int> values = {1, 2, 3, 4, 5};
    ForEach(values, PrintVal);

    // Using lambda
    ForEach(values, [](int value) { std::cout << "From Lambda, Value : " << value << std::endl; });

    return 0;
}