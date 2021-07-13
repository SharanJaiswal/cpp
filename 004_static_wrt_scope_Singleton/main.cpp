// // Singleton is not a language feature, its a design pattern
// // LIFETIME: for how much time the entity will stick around for. How long will it rewmain in our memory before its gets deleted.
// // SCOPE: Where we can acces the variable.
// // It one of the use case is, when we want to use functionality that applies to some global set of data. eg, random number generator
// // Long story short, we just put the global variables or static functions in a single organized blob, by the help of singleton class. This might be flexible.

#include <iostream>

// class Singleton // class that have only one instance
// {
//     private:
//         static Singleton* s_Instance;   // or, static Singleton s_Instance;
//     public:
//         static Singleton& Get(void) { return *s_Instance; } // then, return s_Instance;
//         void Hello(void) { }
// };
// // Declaring the static attri in the accessing scope
// Singleton* Singleton::s_Instance = nullptr; // then, Singleton Singleton::s_Instance;
// int main()
// {
//     #include "../fileio.h"
//     Singleton::Get().Hello();
//     return 0;
// }



// class Singleton
// {
//     public:
//         static Singleton& Get(void)
//         {
//             static Singleton s_Instance; // or, static Singleton *s_Instance;
//             return s_Instance;          // Then, return *s_Instance;
//         }
//         void Hello(void) {}
// };
// int main()
// {
//     #include "../fileio.h"
//     Singleton::Get().Hello();
//     return 0;
// }



// class Singleton
// {
//     // We dont want to have this class constructor because, if its constructor will be present, then it'll give permission to instantiate this class objects outside of this class.
//     // Hence we will make this class constructor private or disabled by any means
//     private:
//         Singleton() {}   // disabling class constructor, to not allowing the instance creation out of this class
//         Singleton(const Singleton&) = delete;    // disabling copy constructor

//         static Singleton s_Instance;

//         float m_MemeberAttr = 0.05f;

//     // Now since constructor is disabled, we will have to provide a way to access this class staticaly
//     public:
//         // we can return reference or pointer of type Singleton as per our choice
//         static Singleton& GetInstance()
//         {
//             return s_Instance;
//         }
//         void DummyFunc() {}
// };
// Singleton Singleton::s_Instance;    // Declaration of static attribute
// int main()
// {
//     #include "../fileio.h"

//     // // Flaws in the below method
//     // Singleton inst1 = Singleton::GetInstance();  // We can actually do this until copy constructor is not disabled
//     // // This will create another instance of Singleton, named 'instance', and will copy all the data of RHS (float data attrs)
//     // // Hence our whole approach shattererd its purpose. 
//     // inst1.DummyFunc();

//     // To combat this
//     Singleton& inst2 = Singleton::GetInstance();    // This is not copying of data. Its just the same single instantiated object from the calss itself. VALID! with or without copy constructor
//     auto& inst3 = Singleton::GetInstance(); // This is also valid. But dont forget to write reference'&'
//     inst2.DummyFunc();
//     inst3.DummyFunc();

//     // However, if we dont delete the copy constructor, this also didn't assured us. We could still create new instance of Singleton class.
//     // Hence, to combat potential human error, we have to delet the copy constructor of Singletoin class
//     return 0;
// }



// Real life implementation, for random number generators, along with some more tweaks aligning with good practices
// time(<time_t *var>|NULL) returns as well as puts value in the var the no. of seconds since epoch
// srand(unsigned int var)
#include <ctime>
class Random
{
    private:
        // This constructor will get called once only
        Random() { srand(time(NULL)); }
        Random(const Random& obj) = delete;
        float GetRandNumImpl() { return rand(); }
    public:
        static Random& GetRandInst()
        {
            static Random s_Instance;
            return s_Instance;
        }
        static float GetRandNum() { return GetRandInst().GetRandNumImpl(); }
};
int main()
{
    #include "../fileio.h"
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;
    std::cout << Random::GetRandNum() << std::endl;

    return 0;
}