#include <iostream>

// everytime when recursive vardiac gets executed, base condition gets looked up.
// If not defined, it wont create any error. But if defined, it will gets executed
void print()
{
    std::cout << "I am empty function and I am called at last.\n";
}

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    std::cout << var1 << std::endl;

    print(var2...);
}

template<typename... Types>
void chaap(Types... var)
{
    ((std::cout << var << std::endl), ...);
}

template <typename... T>
void write(T&... args)
{
    ((std::cout << args << " "), ...);
}

template <typename... T>
void read(T&... args)
{
    ((std::cin >> args), ...);
}

int main()
{
    #include "../fileio.h"
    print(1, 2, 3.14, "Pass me any number of arguments I will print\n");
    chaap(1, 2, 3.14, "Pass me any number of arguments I will print\n");

    int x,y,z;
    read(x,y,z);
    write(x, y, z);
    return 0;
}
