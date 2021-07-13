#include <iostream>
#include <cstring>
#include <string>

struct Vector2  // same concept works for class also
{
    float x, y;
};

class String
{
    private:
        char *m_Buffer;
        unsigned int m_Size;
    public:
        String(const char *string)
        {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];
            // for(int i = 0; i < m_Size; i++) { m_Buffer[i] = string[i]; }
            memcpy(m_Buffer, string, m_Size);
            m_Buffer[m_Size] = 0;   // Null appending string
        }


        // Thats exactly what CPP is doing by its default copy constructor. But we want copying of the memory pointed by the pointer, not the pointer itself.
        // String(const String& other)
        //     // : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}  // M-1: if constructor initializer list is used
        // { memcpy(this, &other, sizeof(String));  }                  // M-2: copying all the bits of the argument


        // Also, below code doesn't allow us to do any kind of copying. We are deleting the copy constructor below
        // String(const String& other) = delete;


        // Here we will implement our own deep copy constructor
        // Any kind of copying is done for same String type, copy constructor will be called everytime, if exist.
        String(const String& other)
            : m_Size(other.m_Size)
        {
            std::cout << "Copying String!" << std::endl;    // For observing that copy constructor is called everytime when any kind of copying is done.

            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);   // m_Size+1 because we know that character pointer string is by default null ternimated.
            // m_Buffer[m_Size] = 0;   // Otherwise we would have explicitly append NULL character at the end of the m_Buffer
        }


        ~String()
        {
            delete[] m_Buffer;
        }

        char& operator[](unsigned int index)    // for [] operator overloading
        {
            return m_Buffer[index];
        }

        friend std::ostream &operator<<(std::ostream &stream, const String &string);    // for accessing pvt member m_Buffer
};
std::ostream& operator<<(std::ostream& stream, const String& string)
{
    // stream << string.GetBuffer();
    stream << string.m_Buffer;
    return stream;
}

void PrintString(String string) // Here also copying is done, Parameter is being copied to the Argument. Both are of String type.
{
    std::cout << string << std::endl;
}

void PrintStringWithReference(String& string)    // to avoid copying of the argument into parameter
{
    std::cout << string << std::endl;
    // Even if we want to copy the passed reference object, uncomment the below line. This is a good practice to always pass by reference.
    // String copy_str = string;    // We copied the parameter value to the new copy_str String variable
}

int main()
{
    #include "../fileio.h"
    Vector2 a = {2, 3};
    Vector2 b = a;  // Shallow copying of the values
    b.x = 10;
    std::cout << "From b::==> x:" << b.x << ", " << "y:" << b.y << std::endl;
    std::cout << "From a::==> x:" << a.x << ", " << "y:" << a.y << std::endl;

    // However, if we use heap for object initialization
    Vector2 *a_ptr = new Vector2();
    Vector2 *b_ptr = a_ptr; // a_ptr and b_ptr is pointing to the same memory address. CHange in one, will reflect in both.
    b_ptr->x = 30;
    a_ptr->y = 20;
    std::cout << "A_PTR's x:" << a_ptr->x << ", y:" << a_ptr->y << std::endl;
    std::cout << "B_PTR's x:" << b_ptr->x << ", y:" << b_ptr->y << std::endl;



    String string = "Sharan";

// shallow copying happening by default (if deep copy constructor is not explicitly defined).
// Char pointer of both will be pointing to same memory (by default, but not now).
// By default, when scope ends, destructor of either one frees the memory, which is again attempted by the another object destructor.
//Hence, program will throw error and will get aborted.
    String second = string; // If copy constructor is deleted, any kind of copying is not allowed

// To demonstrate that same address is being pointed by both of the char pointer of different object, during shallow copy
    second[5] = 'd';    // indexing happens on char pointer. For object of 'String'(NOT actual std::string type), operator [] to be overloaded.

    std::cout << string << std::endl;
    std::cout << second << std::endl;

// What we actually need to do to avoid the error, is to maintain two separate character arrays, instead of character pointers.
// This is called DEEP COPYING.
// Here we will acheive it by using COPY CONSTRUCTOR. When we copy data from one variable to another, of the same type, a copy constructor is implicitly called.
// We will define our owm copy constructor(override the default definition), and define it for deep copy


// Everytime copying is done, copy constructor is being called
    PrintString(string);
    PrintString(second);

    PrintStringWithReference(string);
    PrintStringWithReference(second);

    return 0;
}