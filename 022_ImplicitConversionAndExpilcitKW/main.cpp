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
            : m_Name(name), m_Age(-1) { std::cout << "construct call at func for str" << std::endl; }
        Entity(int age)
            : m_Name("Unknown"), m_Age(age) { std::cout << "construct call at func for int" << std::endl; }
        // If below constructor is commented, then constructor called with a character will not be defined
        // Here, since constructor that takes int is present, therefore, the char ascii is bein interpreted and constructor with int is called
        // But when constructor with int is also not present, then there will be error
        // Hence call constructor with the their available  parameter type
        // Entity(char c)
        //     : m_Char(c) { std::cout << "construct call at func for char" << std::endl; }
        void GetMembers() const
        {
            std::cout << m_Name << ", " << m_Age << ", " << m_Char << "." << std::endl;
        }
};

class Example
{
    private:
        int m_Number;
        String m_Desig;
        float m_Kms;
    public:
        explicit Example(int num)   // parameter can also be const int num
            : m_Number(num), m_Desig("Unga-Bunga") {}
        explicit Example(const String& desig)
            : m_Desig(desig) {}
        Example(const float num)
            : m_Kms(num) {}
};

void PrintEntity(const Entity& entity)
{
    // Some kewl voo-doo stuff !!!!
    entity.GetMembers();
}

void PrintExample(const Example& entity)
{
    // Some kewl voo-doo stuff !!!!
}

int main()
{
    #include "../fileio.h"
    // below, implicit conversion is happening. Only single implicit can happen by C++.
    // It is a type of obj creation also, where RHS is getting converted to Entity type at the end. YES, in the ENTITY TYPE.!!!
    // number is getting caught by the constructor with int parameter
    // While const char pointer need to be converted to be in std::string, since there is parameter of that type in another constructor
    // RHS has to be one of the matchig type of the parametr of the constructor. Otherwise, it'll throw an error.
    // Entity a = "Sharan"; // E R R O R
    Entity a = String("Sharan");
    Entity b = 22;

// Below is very imp concept of copying. Even though PrintEntity is function, not class method, which takes Entity type reference
// but still it can (aprt from entity object) take the object constructor paramaeter because
    PrintEntity(22);
    // PrintEntity("Sharan");  // E R R O R
    PrintEntity(String("Sharan"));
    PrintEntity(Entity("Jaiswal")); // Here, preffered way of creating an object is used, where Entity constructor is being called to create an object, which implictly takes char const and converts it into std::string
    PrintEntity('a');

    // Example ex5 = (String)"geez";   // or just String("geez"), either will work, only if constructor is not explicit

    // EXPLICIT CONVERSIONS
    // We have to mention EXPLICIT keyword infront of the constructor definition in the class.
    // This will disable the implicit conversion for that constructor.
    // Hence, constructor with explicit keyword must be called explicitly. It wont be mapped automatically based on the argument(RHS), as it was happening in the implicit conversion.
    // Example ex1 = 8;     // not happening because to call implicitly the constructor which takes integer argument, we've to call it explicitly.
    // That is, passed object should be of the Example type somewhat
    Example ex2 = (Example)42;  // M-1 : to convert the arg to Entity type
    Example ex3 = Example(35);  // M-2 : to call the constructor explicitly
    Example ex4(78);            // M-3 : Conversion to Example type is happening first

    Example ex5 = (Example)(String)"iowa";
    Example ex6 = Example((String)"Texas");
    Example ex7 = (Example)(String)("Dallas");
    Example ex8((String)"Tuscon");
    PrintExample((Example)(String)"USA");

    return 0;
}