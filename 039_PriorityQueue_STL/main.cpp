// Min heap an max heap(by default)
// Min and Max is based upon the fact that, whenever we try to fetch the element from it, one by one, we get the max|min of from th heap
// minH and maxH have stack kinda implementation; although it is in <queue> library, having alomost all std::queue methods
// They can have multiple similar elements
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main()
{
    #include "../fileio.h"

    // max heap
    std::cout << "Max heap implementation.\n";
    std::priority_queue<int> maxH;
    maxH.emplace(1);
    maxH.push(2);
    maxH.emplace(0);
    maxH.push(3);
// 3 2 1 0

    int n = maxH.size();
    for(int i = 0; i < n; i++)
    {
        std::cout << maxH.top() << std::endl;
        maxH.pop();
    }

    // min heap
    std::cout << "Min heap implementation.\n";
    std::priority_queue<int, std::vector<int>, std::greater<int> > minH;
    minH.emplace(1);
    minH.push(2);
    minH.emplace(0);
    minH.emplace(0);
    minH.push(3);
    minH.push(-8);
    // -8 3 2 1 0 0


    int m = minH.size();
    for (int i = 0; i < m; i++)
    {
        std::cout << minH.top() << std::endl;
        minH.pop();
    }

    // implicit checking is not done when we perform pop over the empty queue. We need to use .empty() method
    // std::cout << minH.top() << "\n";
    // minH.pop();
    std::cout << "IS empty? " << minH.empty() << std::endl;

    return 0;
}