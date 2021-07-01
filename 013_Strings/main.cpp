#include <iostream>
int main()
{
    // STRING LITERALS --> "Sharan" .   What this actually becomes(mutable or immutable), depends on a number of factors. Hover oover the below literal by uncommenting.
    const char* arr = "Sharan\0";  // explicit \0 will be appended at the end even if  null is implicitly mentioned inside the string literal
    // even if const is removed,ie, (char* arr = "Sharan") arr is still immutable, ie, arr[2]='e' is invalid operation. Some compilers may allow it, but this is undefined behaviour, and this mutation should not be practiced.
    // IT SHOULD ALWAYS BE IN PRACTICE TO USE const WHILE DEFINING A STRING LITERAL USING CHARACTER POINTER. DONT IGNORE const WITH CHARACTER POINTER.
    // However, if we define it as an array instead of pointer, then mutaion operation is valid
    char arr1[] = "Sharan";
    arr1[2] = 'e';  // valid operation, since character array is used instead of character pointer, to define a styring literal.
    std::cout << arr1 << std::endl;

    // immutable character pointer
    const char* name = "Shara1";   // just because it is a char pointer, that doesn't mean that it is allocated in heap. It is still in stack memory. If new is used, then delete is used.
    std::cout << name << std::endl;

    char str1[7] = {'S', 'h', 'a', 'r', 'a', '2', 0};
    char str2[6] = {'S', 'h', 'a', 'r', 'a', '3'};  //since we dont have null at end, hence it'll print until null encounters
    std::cout << str1 << std::endl << str2 <<std::endl;

    char str3[7] = "Shan";
    std::cout << sizeof(str3) << "   " << str3 <<std::endl;

    const wchar_t* wstr1 = L"Sharan";   // wide character data type. Append 'L' while defining the string literal
    // THERE IS HUGE CHUNK OF MATERIAL LEFT. Irrelevant for now but it is informative

    return 0;
}
