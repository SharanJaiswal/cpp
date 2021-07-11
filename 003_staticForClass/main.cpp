// // Static methods or static attributes of the class are in namespace of the class, but are not distinct part of every class instance.
// // Unlike static vars and funcs., Static methods or static attributes are not limited to particular translation unit; they are limited to their class.
// // Static attributes are limited to that class instances. Its kind of like, they are global values for every instances of that class.
// // static attributes/methods can be called without a class instance.
// // static methods dont have access to class instances. [kyuki babuji kabhi bhi bete ka phone nahi lete, but beta leta hai]
// // Inside a static method, we cannot write code that refers to the class instance, because we dont have access to it.
// // We can only access the static attributes from static method.
// // However normal class methods can access the static attributes, DUHH!! (because they are for the whole instance of that class.)

// #include <iostream>
// struct Entity 
// {
//     int x, y;
//     void Print(void)
//     {
//         std::cout << x << "," << y << std::endl;
//     }
// };
// int main()
// {
//     Entity e1;
//     e1.x = 2;
//     e1.y = 3;
//     Entity e2 = {4, 5};
//     e1.Print();
//     e2.Print();
//     return 0;
// }

#include<iostream>

struct Entity
{
    static int x, y;

    void Print(void)
    {
        std::cout << x << ", " << y << std::endl;
    }

    static void Display(void)
    {
        std::cout << x << ", " << y << std::endl;
    }
};

// scope of the static variable
int Entity::x /* = some value (it is optional to initialize) */;
int Entity::y /* = some value (it is optional to initialize) */;

int main()
{  
    // M-1 to initialize the static variable
    Entity e1;
    e1.x = 10;
    e1.y = 20;

    // Entity e2 = {30, 40};    // this wont work because x&y are now not Entity class members.
    // M-2 to initialize the static variable
    Entity e2;
    e2.x = 30;
    e2.y = 40;

    // M-3: PREFFERED WAY TO ACTUALLY INITIALIZE THE CLASS STATIC VARIABLE.
    Entity::x = 50;
    Entity::y = 60;

    e1.Print();
    e2.Print();

    // static method call
    Entity::Display();  // PREFFERED WAY
    e1.Display();   // Non-Preffered way
    e2.Display();   // Non-Preffered way
    return 0;
}