// // LIFETIME: for how much time the entity will stick around for. How long will it rewmain in our memory before its gets deleted.
// // SCOPE: Where we can acces the variable.

#include <iostream>

// class Singleton // class that have only one instance
// {
//     private:
//         static Singleton* s_Instance;
//     public:
//         static Singleton& Get(void) { return *s_Instance; }
//         void Hello(void) { }
// };
// // Declaring the static attri in the accessing scope
// Singleton* Singleton::s_Instance = nullptr;
// int main()
// {
//     Singleton::Get().Hello();
//     return 0;
// }

class Singleton
{
    public:
        static Singleton& Get(void)
        {
            static Singleton *s_Instance;
            return *s_Instance;
        }
        void Hello(void) {}
};

int main()
{
    Singleton::Get().Hello();
    return 0;
}