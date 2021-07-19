#include <iostream>
#include <queue>
#include <string>

int main()
{
    #include "../fileio.h"

    std::queue<std::string> Q;
    Q.emplace("Saint");
    Q.push("Sharan");
    Q.emplace("Jaiswal");

    std::cout << Q.front() << std::endl;
    Q.pop();
    std::cout << Q.front() << ", " << Q.back() << std::endl;

    std::cout << Q.size() << std::endl;
    std::cout << "Is empty? " << Q.empty() << std::endl;
    // Q.swap;

    return 0;
}