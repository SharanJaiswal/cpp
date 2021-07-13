// Access to the 'this' keyword is only possible through the member function, that is method; only inside which we can use 'this' keyword
// 'this' is a current object pointer, to which the member function belongs to , and it is called.

#include <iostream>
#include <string>

void PrintEntityWithPointer(Entity* e);
void PrintEntityWithReference(const Entity& e);

class Entity
{
    public:
        int x, y;
        Entity(int x, int y)    // if we dont need to use the constructor initializer list for initializing class member attr
        {
            // x = x;  // we are trying to assign RHS(a argument) to the LHS(member variable). But LHS=LHS or RHS=RHS will be happening only.
            // Entity * const e = this;    // the type of 'this' pointer; a class type of the calling object.
            this->x = x;
            this->y = y;
        }

        // However, if we use 'this' in const function, 'this' will be constant pointer pointing to constant content vars
        int GetX() const
        {
            // const Entity *e1 = this;    // This is a correct line. e1 needs to be of type of 'this'. if const KW is not present then it will throw error
            // e1->x = 5; // this will give error
            return this->x; // Hover over the this KW and see its type. Now uncomment 1st line of this function
        }

        // If we need to access any function defined outside of this class using the object of this class via the class method
        void LogVars()
        {
            PrintEntityWithPointer(this);
            PrintEntityWithReference(*this);

            // delete this;    // Don't ever do that. The reference via 'this' will be gone forever.
        }

        
};

void PrintEntityWithPointer(Entity *e)
{
    std::cout << e->x << ", " << e->y << std::endl;
}
void PrintEntityWithReference(const Entity& e)
{
    std::cout << e.x << ", " << e.y << std::endl;
}

int main()
{
    #include "../fileio.h"
    Entity e0(4,5);
    std::cout << e0.x << ", " << e0.y << std::endl;

    e0.LogVars();
    return 0;
}
