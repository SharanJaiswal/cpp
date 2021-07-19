// HALF PART OF THIS VIDEO LECTURE WHICH CONTAINS TOPICS ABOUT LAMBDA IS NOT COVERED HERE DUE TO :(

#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0;   // marking this attributes mutable ensures that const methods inside this class can modify this variable
    public:
        const std::string& GetName() const  // check how the removal of const keyword, makes instantiation of constant Entity object 'e' invalid, in the first line of main()
        {
            m_DebugCount++;
            return m_Name;
        }
};

int main()
{
    #include "../fileio.h"
    const Entity e;
    e.GetName();

    // Using mutable with lambda function when variables are passed by value
    int a = 8;  // the passed variable should be declared before the lambda function definition.
    // Defining before the function call is absurd, because function doesnt know the variable.
    // passing by value, copying is happening
    auto func = [=]() mutable
    {
        // // If mutable keyword is not present, then we have to locally define a new variable of the same type as of the variable which we are going to manipulate locally in this lambda function
        // int y = a;
        // y++;
        // std::cout << y << std::endl;
        
        a++;
        // this changes happens only in local, actual variable outside of this lambda function remains the same
        // This happens because we are passing value by value, hence coipying is done. We dont use 'mutable' when we use pass the variable by reference
        std::cout << a << std::endl;
    };

    func();

    return 0;
}