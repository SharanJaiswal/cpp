// They are basically used to assign function to the variables, which later can be used as variables, or passes to another function, etc.
#include <iostream>

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

int main()
{
    #include "../fileio.h"
    HelloWorld();

    auto Function = HelloWorld;    // find this instruction address in the mem loc, and return it.
    //Although there will be &HelloWorld, but implicit conversion is taking care of it.

    Function();
    Function();

    return 0;
}