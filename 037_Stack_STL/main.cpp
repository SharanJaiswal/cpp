#include <iostream>
#include <stack>
#include <string>

int main()
{
    #include "../fileio.h"
    std::stack<std::string> S;
    S.push("Saint");    // first entry (bottom-most)
    S.emplace("Sharan");
    S.push("Jaiswal");  // last entry (topmost)

    // for(std::string s : S)      // the iterator wont work on stack
    // {
    //     std::cout << s << " ";
    // } std::cout << std::endl;

    std::cout << "Top element : " << S.top() << std::endl;
    // pop, emplace, push, empty, swap
    std::cout << "Current SIze : " << S.size() << std::endl;
    std::cout << "Is empty ? : " << S.empty() << std::endl;
    
    // we dont have any class method to flush the stack
    // we dont have any kind of front and back method in stack

    return 0;


}