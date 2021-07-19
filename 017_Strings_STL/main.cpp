// std::string takes memory on heap, not on stack
#include <iostream>
#include <string>   // Also contains all the C string functions.

// IGNORE THIS UNTIL ASKED TO LOOK UPON IT.!!!
// void PrintString(std::string string)    // wrong way to mention parameters because when we are passing the class like this to function, we are basically
// creating a copy of that class/object. So, when we perform string+="hello", it wouldn't affect the original 'string' as copy has been passed.
// For just read-Only purpose, such functions work fine. But still this is the wrong way to mention the parameters.
// In copying a string type, we have to dynamically allocate char array on heap, which is costly. So we pass the string type with the constant reference
// we used const because, as per our choice and Business requrement, we dont have to change the orgiginal passed string type data. Also, reference just passing the reference to the original string type. Costly copying is not happening here.
// string += "hello" doesn't work, as its reference is constant.
void PrintString(const std::string& string)
{
    std::cout << string << std::endl;   
}

int main()
{
    #include "../fileio.h"
    std::string str = "Sharan";
    std::cout << str << std::endl;

    // below, we actually tried to add two (const char*) array. Double quoted characters are (const char*) array. They are not actual string
    // std::string str1 = "Sharan" + "Jaiswal";

    // M-1--> std::string type + char* gives std::string type. char* + char* not allowed
    // std::string str2 = " Saint" + "Sharan" + std::string(" Jaiswal");    // NOT ALLOWED
    std::string str2 = std::string("Saint ") + "Sharan" + " Jaiswal";
    std::cout << str2 << std::endl;

    // M-2--> another way of using M-1
    std::string str1 = "ShaIran";
    str1 += " Jaiswal";

    bool contains = str2.find("ai") != std::string::npos;
    std::cout << contains << ". \'ai\' is present at " << str2.find("ai") << std::endl;

    // PASSING STRING AROUND, TO OTHER FUNCTIONS
    PrintString(str1);

    return 0;
}