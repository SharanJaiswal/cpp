#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>

// This is used as predicate for sort STL, for sorting in DESC order
bool f(int x, int y)
{
    return x > y;
}

void VectorDemo()
{
    // O(NlogN)

    std::vector<int> Vector = {11, 3, 2, 14};

    // Sorting using STL
    std::sort(Vector.begin(), Vector.end());

    std::cout << "Sorted vector :" << std::endl;
    for (int x : Vector)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Check if element is present.  Works only with the sorted iterable
    bool present = std::binary_search(Vector.begin(), Vector.end(), 2);
    std::cout << present << std::endl;

    Vector.emplace_back(14);
    Vector.emplace_back(14);
    Vector.emplace_back(14);
    Vector.emplace_back(14);
    Vector.emplace_back(14);
    Vector.emplace_back(100);
    // 2 3 11 14 14 14 14 14 14 100
    // Finding the first occurence of the element in the SORTED iterable, if present.
    // If element to be searched is not present, then first occurence of number > the number to be found is returned.
    // It returns the pointer. Hence subtracting return value by the OBJECT.begin() will give the index of it
    // else it returns the pointer, to which the index will be out of the bound, ie, max_index+1
    auto ptr = std::lower_bound(Vector.begin(), Vector.end(), 14); // put 200, 15 etc and check the result
    int idx = ptr - Vector.begin();
    if (idx >= Vector.size())
        std::cout << "No element present greater than this." << std::endl;
    else
        std::cout << "First occurence of element >= is present at index : " << idx << std::endl;

    // For upper bound, it ret ptr to the first occurence of number strictly greater than the last occurence of number as parameter
    // If parameter number is not present, first occurence of number just greater than that, its ptr is returned
    // if parameter no is present and it is max in the iterable, then idx from ptr is size
    // If param num is greater than max value in the iterable, then idx to ptr is size
    // 2 3 11 14 14 14 14 14 14 100
    ptr = std::upper_bound(Vector.begin(), Vector.end(), 1000); // use 11, 14, 100, 1000
    idx = ptr - Vector.begin();
    std::cout << idx << std::endl;
    // NOTE: if element exist in sorted iterable, then difference b/n lowera nd upper bound gives the count of the element

    // Sorting in desc using sort STL
    std::sort(Vector.begin(), Vector.end(), f);

    std::vector<int>::iterator itr;
    for (itr = Vector.begin(); itr != Vector.end(); itr++)
    {
        std::cout << *itr << ", ";
    }
    std::cout << std::endl;
}

void SetDemo()
{
    // O(logN)
    // To use binary search, upper bound and lower bound , etc on std::vector, we have to sort it first
    // But what if we need to find upper bound, lower bound, etc for a number in an ordered list w/o explicitly performing the sorting
    // For that, we use SET. by default, it maintains the asc order of the order, with every element inserted
    std::set<int> Set;
    Set.insert(1);
    Set.insert(2);
    Set.insert(-1);
    Set.insert(-10);

    // -10 -1 1 2
    for (int element : Set) // To observe the implicit ordering
        std::cout << element << ", ";
    std::cout << std::endl;

    // Check if the element is preset or not
    std::set<int>::iterator itr;
    itr = Set.find(-1);
    if (itr == Set.end())
        std::cout << "Not present\n";
    else
    {
        std::cout << "Present\n";
    }

    // -10 -1 1 2
    // lower bound and upper bound for set dont take the begin and end iterator, since set is already sort
    std::cout << *(Set.lower_bound(-1)) << std::endl; // >=
    std::cout << *(Set.upper_bound(1)) << std::endl;  // >
    std::cout << *(Set.upper_bound(0)) << std::endl;
    std::cout << *(Set.upper_bound(2)) << std::endl; // returns Set.end()

    // Set.erase(iterator);

    // Set.count(<element>) return 1 or 0; used to check the prescence of the element
}

void MapDemo()
{
    // maps something to something. O(logN)
    std::map<int, int> m1;
    m1[2] = -1;
    m1[1] = 100;
    m1[82734] = 1;
    m1[3] = 200;

    // since it is ordered map, hence keys will be stored in sorted order. first and second are used for key and value
    std::map<char, int> cnt; // for frequency
    std::string name = "sharan jaiswal";
    for (char c : name)
        cnt[c]++;

    std::cout << cnt['a'] << " " << cnt['s'] << std::endl;

    // find and erase also works. m1.find(<key>) (returns iterators of that element if present, otherwise the .end());
    //  m1.erase(<key>);
    // m1.count(<key>) is used to check the prescence of the key val pair in the map conatiner; returns bool value
}

void SetPairQues()
{
    // Program to find the range where given num exist. Range do not overlap, ends exclusive
    std::set<std::pair<int, int>> S;
    // below insertion inset will be auto sorted by comparing pairs, in asc order.
    S.insert({410, 450});
    S.insert({10, 20});
    S.insert({3, 4});
    S.insert({30, 400});
    int n = 2;

    std::pair<int, int> pair = {n, INT16_MAX};
    std::set<std::pair<int, int>>::iterator itr = S.upper_bound(pair);
    if (itr == S.begin())
    {
        std::cout << "Not present" << std::endl;
        // return 0;
        return;
    }
    itr--;
    if (n >= itr->first && n <= itr->second)
    {
        std::cout << "Present in : [" << itr->first << ", " << itr->second << "]" << std::endl;
    }
    else
    {
        std::cout << "Not present" << std::endl;
    }
}

int main()
{
    #include "../fileio.h"
    
    // unordered map O(1)
    // codeforces divide array in two with equal sum; only one pair swap is allowed
    // Output: Yes/No

    int n;
    std::cin >> n;
    std::vector<int> A(n, 0);   // Vector of size 'n' is initialized with '0'.

    for(int i = 0; i < n; i++)
        std::cin >> A[i];
    
    long long sum = 0;  // totla sum of the vector
    for(int &x : A)
        sum+=x;
    
    if(sum&1)
    {
        std::cout << "No" << std::endl;
        return 0;
    }
    
    std::map<int, int> first, second;
    first[A[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        second[A[i]]++;
    }

    long long sumFirst = 0;
    for(int i = 0; i < n; i++)
    {
        sumFirst += A[i];   // sum of first i numbers
        if(sumFirst = sum/2)
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        else if(sumFirst < sum/2)
        {
            long long x = sum/2 -sumFirst;
            // delete element from second half, and insert in first half
            if(second[x] > 0)
            {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
        else    // if sumFirst > sum/2
        {
            long long y = sumFirst - sum/2;
            if(first[y] > 0)
            {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
        first[A[i+1]]++;
        second[A[i+1]]--;
    }
    std::cout << "No" << std::endl;

    // if in range based for loops where we iterate over pairs, auto& [key, value]; auto& kv ==> kv.first|second; 
    // or, just by normal iterator, itr->first|second

    return 0;
}