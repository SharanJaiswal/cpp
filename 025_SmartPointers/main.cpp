// https://en.cppreference.com/w/cpp/memory/shared_ptr
// Smart pointers help to save a step of calling delete function for freeing the dynamiclly allocated memory. It automates that part.
// Smart pointers are kind of wrapper around real raw pointers. They are of many types
#include <iostream>
#include <string>
#include <memory>   // for accessing smart pointers for the programs

class Entity
{
    public:
        Entity()
        {
            std::cout << "Entity Created." << std::endl;
        }
        ~Entity()
        {
            std::cout << "Entity Destroyed." << std::endl;
        }
        void Print() {}
};

int main()
{
    #include "../fileio.h"
    std::cout << "Now unique pointers." << std::endl;
    // Unique pointers: memory pointed by this knid of pointers, wont be pointed by any other pointers during their lifetime. It is scoped pointer, and when scope ends, deletes the memory on heap automatically
    // If 2 unique pointers pointing to same memory, and if one frees the memory, then other will point to memory that is being freed, which is DUMB THING! Hence, we cant copy unique pointers.
    // They have explicit constructors. Also, since we cant assign/copy unique pointers to another unique pointers, hence their copy constructors are deleted/disabled.
    {
        // std::unique_ptr<Entity> entity(new Entity());   // M-1 since its unique_ptr constructor is explicit.
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();    // M-2 Preffered way to handle the exception. Otherwise we'll get some dangling point due to error, with no reference to the memory, creating a memory leak.
        entity->Print();    // accssing the object attributes and methods via unique pointer
        // std::unique_ptr<Entity> e0 = entity;    // since copy constructor is deleted for the unique pointer, hence copying is not allowed.        
    }

    std::cout << "Now shared pointers." << std::endl;
// Shared Pointer: It works via "reference counting". It means, we keep track of how many reference we have to a particular pointer.
// As soon as reference count reaches to the count of ZERO, it deleted the memory on heap.
    {
        std::shared_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();    // M-2. M-1 is same as of unique pointer
            // Avoid M-1 here because, shared pointer has to allot another block of memory as control block, where it stores a reference count.
            // If we create with M-1, with 'new' and then pass it to shared pointer constructor, then we'll be creating two different block of memory, one for storage and another as a control block separately, at different times; which is less efficient.
            // Hence, follow M-2 for contrusting both of the blocks together, which is a lot more efficient.
            e0 = entity;    // copying is allowed, unlike unique pointer. This will increase the reference count implicitly during copying of the shared pointer.
        }   // e0 lifetime not ended, still reference to same memory location.
            // Howeveer, just the scope of the entity shared pointer gets popped out of the stack record.
            //Hence, destructor not called for that Entity object.
    }   // Even, e0 scope is popped out of the stack frame. So now the reference count is 0. Hence, memory will be deleted, thus object deleted.

    std::cout << "Now weak pointers." << std::endl;
// Weak pointers are used along with the shared pointers. We copy the value of the shared pointer to the weak pointer.
// While copying, the reference count does not increase. It jsut keeps the value to itself.
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            e0 = entity;    // Copying is happening but at Background, reference count is not increasing for the shared pointer.
            
            // Below next 3 lines are used for observing the use_count() of both weak_ptr and shared_ptr
            // In both type of pointer, use_count() always shows the total no of shared_ptr pointing to the same memory loctaion
            std::shared_ptr<Entity> tst_ent = entity;
            std::weak_ptr<Entity> e1 = entity;
            std::weak_ptr<Entity> e2 = entity;

            if (!e0.use_count()) // for weak pointers, 'expired()' can also be used, but not '==' operator
            { std::cout << "Not a valid weak pointer" << std::endl; }
            else { std::cout << "Valid weak pointer. Count is:" << e0.use_count() << std::endl; }

            if(!entity.use_count()) // for shared pointers; '==' oparator can also be used but it is risky, because shared pointer can be wild pointer also
            { std::cout << "Not Valid shared pointer." << std::endl; }
            else { std::cout << "Valid shared pointer. Count is:" << entity.use_count() <<  std::endl; }
        }
         if(!e0.use_count())    // for weak pointers, 'expired()' can also be used, but not '==' operator
         { std::cout << "Not a valid weak pointer" << std::endl; }
         else { std::cout << "Valid weak pointer. Count is:" << e0.use_count() << std::endl; }

        // Below ont work because 'entity' named shared variable no longer exist, cuz it got popped out of stack frame
        // if(!entity.use_count())
        // { std::cout << "Not Valid shared pointer." << std::endl; }
        // else { std::cout << "Valid shared pointer." << std::endl; }

        // After inner block ends, entity scope ends. So, it is popped out. E0's scope is still present. It still points to the memory.
        // However, since entity scope ends, reference count sets back to 0. This will delete the memory and calls destructor.
        // Here, e0 is pointing to the invalid memory now. This weak pointer can be used to check if the memory to which it is pointing is still valid or not.
    }   // Here, the scope of E0 ends, it will popped out the programs stackframe memory.

    return 0;
}