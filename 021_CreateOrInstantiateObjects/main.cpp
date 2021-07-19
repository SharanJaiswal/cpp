#include <iostream>
#include <string>
using String = std::string;

class Entity
{
    private:
        String m_Name;
    public:
        Entity() : m_Name("Unknown") {}
        Entity(const String& name) : m_Name(name) {}
        ~Entity() { std::cout << "Destruct Ent." << std::endl; }

        const String& GetName() const { return m_Name; }
};

class ScopedPtr
{
    private:
        Entity *m_Ptr;
    public:
        ScopedPtr(Entity *ptr)
            : m_Ptr(ptr)
        {
            std::cout << "Scope Begins." << std::endl;
        }
        ~ScopedPtr()
        {
            std::cout << "Scope Ends." << std::endl;
            delete m_Ptr;
        }
};

int main()
{
    #include "../fileio.h"
    // Method-1 (creating object on stack. Scope bound. Evem if there is an empty scopes where we have  just { ... })
    // It is comparetively faster than that on heap memory.
    Entity e1; // or Entity e1("Sharan")
    std::cout << e1.GetName() << std::endl;
    // Below two are the fastest and managed and most preffered way to create an object in C++
    Entity e2 = Entity();
    std::cout << e2.GetName() << std::endl;
    Entity e3 = Entity("Jaiswal");
    std::cout << e3.GetName() << std::endl;
    // Entity e6 = "Jhakaas";   // It wont work because the constructor is taking a std::string, but we are providing const char*
    // Since only one implicit conversion can take place, which is happening by converting the RHS to Entity type, another implicit conversion cant happen.
    Entity e5 = String("Er. SSJ");  // This will work fine because the argument passed to the parameterized constructor is of std::string type.
    // Now, one implicit conversion can be happen, ie, RHS to Entity type.
    std::cout << e5.GetName() <<std::endl;

    Entity *e;
    {
        Entity e4("Saint");
        e = &e4;
        std::cout << e->GetName() << std::endl;
    }   // pointer will be there however empty scope block will gets vanished after its lifetime ends
    std::cout << e->GetName() << std::endl; // It shouldn't work, because object scope ended and its popped out of the stack frame

    // Method-2 (creating objects on heap memory) It is slow comparetively
    Entity *e_ptr = nullptr;    // initializing a Entity pointer on stack
    {   // empty scope block
        Entity *e_ptr_in = new Entity("Sharan Jaiswal.");   // initializing mem on heap, pointer by another pointer in stack with limited scope.
        e_ptr = e_ptr_in;   // to avoid memory leaks and to use the alloted heap memory, we are copying address to the larger scope pointer
        std::cout << e_ptr_in->GetName() << std::endl;
    }
    // std::cout << e_ptr_in->GetName() << std::endl;   // this wont work because inside pointer on stack gets popped out of the stack
    std::cout << e_ptr->GetName() << std::endl;     // this works because the scope of the outer pointer is still not ended
    delete e_ptr;   // freeing the memory on the heap
    e_ptr = nullptr;    // good practice to avoid wild/dangling pointer

    // https://www.geeksforgeeks.org/how-to-initialize-array-of-objects-with-parameterized-constructors-in-c/

// ---------------------------------------------------------------------------------------------------------------------//
// SCOPE OF OBJECT CREATED ON HEAPS
// Although object instantiated on heap may last till the program ends, or unless it is explicitly freed.
// But we can free the object on heap, once its scope of block ends
// Here, memory on heap will be freed, as well as, the pointer will be popped out of the stack memory
    {
        ScopedPtr ptr = new Entity();
    }

    return 0;
}