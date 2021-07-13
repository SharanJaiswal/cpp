#include <iostream>
#include <string>

using String = std::string;

class Entity
{
    private:
        String m_Name;
        int m_Age;
        char m_Char;
    public:
        Entity(const String& name)
            : m_Name(name), m_Age(-1) {}
        Entity(int age)
            : m_Name("Unknown"), m_Age(age) {}
};

class Example
{
    private:
        int m_Number;
        String m_Desig;
    public:
        explicit Example(int num)
            : m_Number(num), m_Desig("Unga-Bunga") {}
        Example(const String& desig)
            : m_Desig(desig) {}
};

void PrintEntity(const Entity& entity)
{
    // Some kewl voo-doo stuff !!!!
}

int main()
{
    #include "../fileio.h"
    // below, implicit conversion is happening. Only single implicit can happen by C++.
    // It is a type of obj creation also, where RHS is gettingconverting to Entity type at the end. YES, in the ENTITY TYPE.!!!
    // number is getting caught by the constructor with int parameter
    // While const char pointer need to be converted to be in std::string, since there is parameter of that type in another constructor
    // RHS has to be one of the matchig type of the parametr of the constructor. Otherwise, it'll throw an error.
    // Entity a = "Sharan"; // E R R O R
    Entity a = String("Sharan");
    Entity b = 22;

    PrintEntity(22);
    // PrintEntity("Sharan");  // E R R O R
    PrintEntity(String("Sharan"));
    Example ex5 = (String)"geez";
    PrintEntity(Entity("Jaiswal")); // Here, preffered way of creating an object is used, where Entity constructor is being called to create an object, which implictly takes char const and converts it into std::string


    // EXPLICIT CONVERSIONS
    // We have to mention EXPLICIT keyword infront of the constructor definition in the class.
    // This will disable the implicit conversion for that constructor.
    // Hence, constructor with explicit keyword must be called explicitly. It wont be mapped automatically based on the argument(RHS), as it was happening in the implicit conversion.
    // Example ex1 = 8;     // not happening because to call implicitly the constructor which takes integer argument, we've to call it explicitly.
    // That is, passed object should be of the Example type somewhat
    Example ex2 = (Example)42;  // M-1 : to convert the arg to Entity type
    Example ex3 = Example(35);  // M-2 : to call the constructor explicitly
    Example ex4(78);            // M-3 : Conversion to Example type is happening first
    return 0;
}