// They are like macros, can do pretty much anything
// They areused to avoid defining multiple function overloads for a given function names.
// For a single function, templates can be defined, and it will decide what kind of execution to proceed, based on certain condition.
// conditions like, different paramater type, for which by convention,  we were using function overloads.
#include <iostream>
#include <string>

// Here we are overloading the function for every different argument change. Although the internal working of the function is just same for every below overloaded function.
// the only difference occures because of the parameter data type
// We can use the template for this, and sqeeze it to the single function
// void Print(int value)
// {
//     std::cout << value << std::endl;
// }
// void Print(std::string value)
// {
//     std::cout << value << std::endl;
// }
// void Print(float value)
// {
//     std::cout << value << std::endl;
// }

// Way to do this using template: Before the return type, we write the codeline
template<typename T>    // in template parameter, we use 'typename' as the type of the template parameter, and a variable for typename as 'T'(can be Type, type, sharan, etc.)
void Print(T value)     // 'typename' is alias to 'class' here. Hence, we could also write <class T>
{
    std::cout << value << std::endl;
}
// This is not actual function but it is a template. It gets converted to function when we call it, based on how we call it, based on the type of the argument passed(in this case)


//templates for class
template<int N>   // for array size
class Array
{
    private:
        int m_Array[N];
    public:
        int GetSize() const { return N; }
};
// New class
template<typename T, int N>
class Arr
{
    private:
        T m_Array[N];
    public:
        int GetSize() const { return N; }
};


int main()
{
    #include "../fileio.h"

    Print(5);
    Print("Sharan");
    Print(5.5f);
    // since the type is getting perceived implicitly by the template, which is kind of difficult for us to read.
    // We can explicitly mention the type of argument to be read as by the template typename
    Print<int>(7);
    Print<float>(4.8f);
    Print<std::string>("Jaiswal");


// templates for class
    Array<5> array;
    std::cout << array.GetSize() << std::endl;

    Arr<int, 6> arr0;   // create an array of type integer and of size 6, by instantiating the 'Arr' class object
    std::cout << arr0.GetSize() << std::endl;
    Arr<std::string, 3> arr1;   // creates an std::string type array of size 3, by instantiating 'Arr' class object
    std::cout << arr1.GetSize() << std::endl;

    return 0;
}