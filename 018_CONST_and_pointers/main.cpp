#include <iostream>

// IGNORE CLASSES AS OF NOW. JUMP STRAIGHT TO MAIN() FUNCTION.
class Entity
{
    private:
        int m_X, m_Y, m_Z;
        int* point_Y = &m_Y;
        mutable int m_W;
    public:
        int GetX() const    // writing const at the right of the function name. THIS IS ONLY VALID/WORKS INSIDE OF CLASS.
// This imposes restriction on GetX function to NOT modify any of this class member variables.ie, they can be modified(if they are allowed), but not from this function
        {
            // m_X = 2; // we cant change the class attribute value.
            return m_X;
        }

        // below function returns a pointer whose dereferenced value cant be modified out of this function, but it can be modified inside of this function
        // the contents of the returned pointer can't be modified out of this function, but it can be modified inside of this function,
        // and of course, function cant modify the class member eg, point_Y
        const int* const GetY() const
        {
            *point_Y = 5;   // Allowed because, we are not modifying the member point_Y, but the address that this pointer is pointing to.
            // point_Y = &m_X;  // Not allowed
            return point_Y;
        }

// below method is used for certain demonstration for the PrintEntity function, outside of this class, defined below this class.
        int GetZ() const
        {
            return m_Z;
        }
    // The above GetZ() method can have two versions. One with 'const' keyword; other without it. And they both work perfectly fine.
    // Always mark methods as 'const' if they are not supposed to modify the class. It is a good practice.

    // There are special class attributes which can be mutated inside the const methods. They need to be prepended with 'mutable' keyword at their definition.
        void mut_W() const
        {
            m_W = 2;
        }
};

void PrintEntity(const Entity& e)
{
    // e = Entity();    // invalid operation, since we took original object as a constant, and we cant modify the contents of the constant objects. JUST LIKE WITH POINTERS
    // Long story short, the parameter of the function ensures that the entity object that we are taking as an argument on the promise that we dont change that object's content
    // So, if we remove the 'const' keyword form the GetZ() method after its name, this will create VIRODHBHAS.ie, at one place we are promising that we wont change
    // the content of the object 'e', taken as an argument; while on the other hand, we are not sure that GetZ(), the one which is called inside this function, 
    // wont change the entity object 'e'. Although, there is no statement like m_Z = <some_new_vale> inside of GetZ() method, but this function isn't assured.
    // unless 'const' keyword is being added after the GetZ() method name.
    // TRY ONCE COMMENTING THE 'const' KEYWORD AFTER THE 'GetZ()' METHOD OF 'Entity' CLASS. THE BELOW LINE WILL TURN INVALID.
    // This function can only call any 'const' methods of Entity class, which ensures immutation of the object attributes.
    std::cout << e.GetZ() << std::endl;
}


int main()
{
    #include "../fileio.h"
    const int MAX_AGE = 90; // lets define a constant integer
    int* a  = new int;  // we DEFINED a new integer pointer. It has some garbage value by default.
    std::cout << a << " : " << *a <<std::endl;
    *a = 2;
    std::cout << a << " : " << *a << std::endl;

    // Below will give error
    // a = &MAX_AGE;    // reassigning a const pointer to pointer valriable falis here. But to bypass this, we've below method
    a = (int*)&MAX_AGE; // However, chances are that this will crash because, we are trying to modify the read-only section. SO DONT BE A HERO. LET const serve ITS PURPOSE
    std::cout << a << " : " << *a << std::endl;
    *a = 80;    // here we are hoping that value of MAX_AGE will be changed by bypassing its const constraint
    std::cout << "MAX_AGE: " << MAX_AGE << ", a: " << a << ", *a: " << *a << std::endl; // GHANTA CHANGE HUA. it was a read-only memory. Be thankful that program didn't crash.

    const int *b = new int; // making the contents of the address constant, not the address constantly stick to the variable b. [int const* b = new int]
    // *b = 2;  // INVALID OPERATION. here weare trying to dereference the pointer and change the value of it, which is not possible
    // HOWEVER READING CONTENTS OF THE ADDRESS IN  variable b IS TOTALLY FINE.
    std::cout << "b: " << b << ", *b: " << *b << "(Garbage value)" << std::endl;
    // This (below) works as we are changing the value of variable 'b', not the value of the address that is contained in var 'b'. Momentarily, it makes contents of that address constant
    b = a;

    int* const c = new int; // we can change the contents of the pointer, but cant reassign any other address to the integer pointer 'c'.
    std::cout << "c: " << c << std::endl;
    // c = nullptr;  // INVALID OPERATION

    const int* const d = new int;   // neither can change the pointer value, nor the contents of the value pointed  by the pointer variable

    // go, have a look on the class
    return 0;
}