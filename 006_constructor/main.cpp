// constructor is a special type of method that runs everytime when we CREATE or instantiate an object, by any means.
// they have name same as the class name with NO RETURN TYPE(NOT EVEN VOID !!!)
// they wont run if object dont get instantiated. eg, if we just run static method from class, they wont run.
// when we use 'new' keyword, we  create a new object instance. Hence it will call the constructor

#include<iostream>

class Entity    // normal constructor creation and its overloading
{
    public:
        float X, Y;
        Entity()
        {
            X = 0.0f;
            Y = 1.0F;
        }
        Entity(float x, float y)
        {
            X = x;
            Y = y;
        }
        void Print()
        {
            std::cout << X << ", " << Y << std::endl;
        }
};

// if we want to create the class with static function where we just want to use its static func, but dont want users to create the class instance.
class Log
{
// METHOD 1:---(STARTS)
// since CPP gives default constructor when obj is created, obj cant call its constructor SINCE ITS PVT MEMBER OF CLASS. If constructor cant be called => NO OBJ CREATED.
    private:
        Log() {}
// METHOD 1:---(ENDS)
    public:
// METHOD 2:---(STARTS)
        // Log() = delete   // we are telling cpp compiler that we dont need this class' constructor.
        static void Write(void)
        {
        }
};

int main()
{
    Entity e1;
    e1.Print();
    Entity e2(10.0f, 5.0f);
    e2.Print();

    Log::Write();
    // Log obj; // this line will show error
    
    return 0;
}