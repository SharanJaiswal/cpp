// destructor apPlies on both stack and heap allocated objects. So if obj is allocated using 'new' & if we call 'del' on obj, the destruct will get called.
//  Since objects generally created on stack, hence when the scope of that instance ends, destructor will get called.
#include <iostream>
class Entity // normal constructor creation and its overloading
{
public:
    float X, Y;
    Entity()
    {
        std::cout << "Default Constructed Entity." << std::endl;
        X = 0.0f;
        Y = 1.0F;
    }
    Entity(float x, float y)
    {
        std::cout << "Parameterized Constructed Entity." << std::endl;
        X = x;
        Y = y;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity." << std::endl;
    }
    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

int main()
{
    Entity e1;
    e1.Print();
    Entity e2(10.0f, 5.0f);
    e2.Print();
    e2.~Entity();    // not a good practice to call destructor manually. Instead, use free() if possible.

    return 0;
}