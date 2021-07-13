#include <iostream>

class Entity
{
    private:
        int x;
    public:
        Entity(int num)
        {
            x = num;
        }
        void Print()
        {
            std::cout << "Hello! The number is : " << x << "." << std::endl;
        }
};

class ScopePtr
{
    private:
        Entity *m_Ptr;
    public:
        ScopePtr(Entity *ptr)
            : m_Ptr(ptr) {}
        ~ScopePtr()
        {
            delete m_Ptr;
        }

// Below both will return the Entity object pointer. First is via ScopePtr method. Other is via overloading operator '->'
        Entity *GetEntObj()     // More cluttered, less readable
        {
            return m_Ptr;
        }
        Entity *operator->()    // Less clutter, more readable
        {
            return m_Ptr;
        }

        Entity *operator->() const
        {
            return m_Ptr;
        }
};


// IMPLEMENTATION TO FIND THE OFFSET OF THE VARIABLE
struct Vector3
{
    char a;
    double c;    
    int b;
};

int main()
{
    #include "../fileio.h"
    ScopePtr entity = new Entity(5);
    entity.GetEntObj()->Print();    // Very cluttered way
    entity->Print();                // Non-cluttered way
// (Although, entity is of ScopePtr type whic normally cant access Print() method of Entity class just by using '->' operator)
// Hence, redefined that part by overloading -> operator

// For below type
    const ScopePtr ent = new Entity(10);
    ent->Print();



// OFFSET IMPLEMENTATION
    // Access the variables of the struct, but not from their addresses, rather from 0(x), 4(y), 8(z) [order of declaration]
    int offset = (long)&((Vector3 *)nullptr)->a;
    std::cout << offset << std::endl;
    offset = (long)&((Vector3 *)0)->b;
    std::cout << offset << std::endl;
    offset = (unsigned long)&((Vector3 *)nullptr)->c;
    std::cout << offset << std::endl;

    return 0;
}