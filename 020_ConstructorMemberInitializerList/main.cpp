// Way to initialize class member(attrs)/method in the constructor
#include <iostream>
#include <string>

// // Method-1
// class Entity
// {
//     private:
//         std::string m_Name;
//     public:
//         Entity()
//         {
//             m_Name = "Unknown";
//         }
//         Entity(const std::string& name)
//         {
//             m_Name = name;
//         }
//         const std::string& GetName() const
//         {
//             return m_Name;
//         }
// };
// int main()
// {
//     #include "../fileio.h"
//     Entity e0;
//     std::cout << e0.GetName() << std::endl;
//     Entity e1("Sharan");
//     std::cout << e1.GetName() << std::endl;
//     return 0;
// }


// // Method-2
// class Entity
// {
//     private:
//         std::string m_Name;
//         int m_Score;
//     public:
//         Entity()
//             : m_Name("Unknown"), m_Score(300)   
//             // indent colon CS-attrs with bracket for its initial value.
//             // initialize in same order as it is declared/defined to avoid depencency issues
//             // because compiler will follow the order in which members are declared/defined
//         {
//         }
//         Entity(const std::string& name)
//             : m_Name(name)
//         {
//         }
//         const std::string& GetName() const
//         {
//             return m_Name;
//         }
// };
// int main()
// {
//     #include "../fileio.h"
//     Entity e0;
//     std::cout << e0.GetName() << std::endl;
//     Entity e1("Jaiswal");
//     std::cout << e1.GetName() << std::endl;
//     return 0;
// }



// // // // // // // // // // // // // // // // // // // // //
// // // // // // // // C A U T I O N // // // // // // // //
// // // // // // // // // // // // // // // // // // // //
// If we run the below code, we will create two instances of the Example class, everytime when we initialize the Entity class object
// First, it'll be created in the Entity private member section. It'll initialize Example object w/ calling Example constructor w/o any argument
// Second, it'll create another example object in the Entity's w/o param constructor, and will assign to variable m_Example, by discarding old already created Example instance
// This will impact performance. This doesn't happen with primitive data types
// However, if we initialize the member in the list, this will create only one instance, from the member initializer list only
class Example
{
public:
    Example()
    {
        std::cout << "Created Example!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Example with x = " << x << "!" << std::endl;
    }
};
class Entity
{
private:
    std::string m_Name;
    int m_Score;
    Example m_Example;

public:
    Entity()
        // uncomment either of the below method, along with commenting m_Example initializer line inside of the Entity constructor block
        // : m_Example(Example(8))  // Method-1
        // : m_Example(8)           // Method-2

    {
        m_Name = std::string("Unknown");
        m_Example = Example(8); // I'm talking about this line!
    }
    Entity(const std::string &name)
        : m_Name(name)
    {
    }
    const std::string &GetName() const
    {
        return m_Name;
    }
};

int main()
{
    #include "../fileio.h"
    Entity e0;
    Entity e1 = std::string("Sharan");
    // Although parameterized constructor is called, but still members will have get initialized, for the object.

    return 0;
}