#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <unordered_map>

// This is used as predicate/comparator for sort STL, for sorting in DESC order
bool f(int x, int y)
{
    return x > y;
}

void VectorDemo()
{
    // O(NlogN)

    std::vector<int> Vector1 = {11, 3, 2, 14}; // or, std::vector<int> Vector{11,3,2,14};

    std::vector<int> Vector = {11, 3, 2, 14, 86, 94};
    std::cout << "size:" << Vector.size() << "; Capacity:" << Vector.capacity() << std::endl;

    Vector = Vector1;
    // '=' assignment operator is overloaded in vectors, used to do deep copying. Original vector elements gets destroyed, replaced by new. Capacity remains same.
    std::cout << "size:" << Vector.size() << "; Capacity:" << Vector.capacity() << std::endl;

    std::vector<int> vectZ; // Also, using copy constructor for deep copy as, std::vector<int> vectZ(Vector);
    vectZ = Vector;
    vectZ[0] = 78;
    Vector[0] = 12;
    std::cout << " To demons = and deep copy through = " << vectZ[0] << ", " << Vector[0] << std::endl;

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
    // else it returns the pointer .end(), to which the index will be out of the bound, ie, max_index+1
    auto ptr = std::lower_bound(Vector.begin(), Vector.end(), 14); // put 200, 15 etc and check the result
    int idx = ptr - Vector.begin();
    if (idx == Vector.size())
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
    // NOTE: if element exist in sorted iterable, then difference b/n lower and upper bound gives the count of the element

    // Sorting in desc using sort STL
    std::sort(Vector.begin(), Vector.end(), f);

    std::vector<int>::iterator itr;
    for (itr = Vector.begin(); itr != Vector.end(); itr++)
    {
        std::cout << *itr << ", ";
    }
    std::cout << std::endl;

    // vectors of pair
    std::vector<std::pair<int, int>> PairVect1;
    PairVect1.emplace_back(1, 2); // empalce_back wont take braces, but push_back will. Hence, remember either of them
    PairVect1.push_back({3, 4});
    std::vector<std::pair<int, std::pair<int, int>>> NestPairVect; // prefer use of std::make_pair() in nested pairs
    NestPairVect.push_back({3, {6, 7}});
    // NestPairVect.emplace_back({2, {6,7}});   // since this is not working, even w/o removing {}; we'' use make_pair()
    NestPairVect.emplace_back(std::make_pair(2, std::make_pair(6, 7)));
    std::cout << NestPairVect[0].second.second << ", " << NestPairVect[0].second.first << ", " << NestPairVect[0].first << std::endl;

    std::vector<std::pair<int, int>> PairVect2(4, {6, 9}); // initializing vector of pair of size 4 with pair values {6,9}
    // If initial value is not given, then garbage value is being present
    std::vector<std::pair<int, int>> PairVect3(PairVect1); // copying is allowed only at definition.
    // PairVect3(PairVect1);   // this wont work. copying later at some point, other than at the point of initialization

    // few other ways of copying
    // std::vector<int> vect1{1,2,3,4,5};   std::vector<int> vect2(vect1.begin()+1, vect1.end()-1)
    // Similarly we can use AN ARRAY as the source of data at the time of vector copying, along with the array nemonic arithmetic
    // '=' assignment operator also work

    // .end() ==> points to the memory element, next to the last
    // .begin() ==> points to the first element
    // .rend() ==> similar to end, points to one before the first element
    // .rbegin() ==> points to the last element
    // .cbegin()|.cend() ==> returns constant iterator
    // .crbegin()|crend() ==> returns constant reverse iterators
    // if auto itr = vect.cbegin(); .cbegin() will make sure that itr wont gets changed. Its like const auto itr
    // .cend() ==> similar to the end, but makes itr constant

    // .INSERT() method with vectors: returns the iterator to the last element inserted, ie, first of the series of elements inserted
    // Also, after insertion, if vector reallocation happens, that initial itr is no longer valid. Returned value from insert will point to reallocated vector element inserted last
    // param first will be position of dest. If 2 params are used, second will be the element
    // If 3 params are used, 2nd will be the count, of the third element to be inserted
    // If 3 params are used, 2nd and 3rd will be the start and end pointer to the source contiguous memory
    std::vector<int> fin(3, 100);                            // creating vector of size 3 with default value of 100 each
    fin.insert(fin.begin() + 1, 45);                         // if 2 params is passed, first denotes the palce at which value will be inserted, and second denotes the value itself
    fin.insert(fin.begin(), 2, 87);                          // first denotes the starting place of the value at which they will be inserted, third denotes the value itself, second denotes the count of values inserted
    std::vector<int> fan(3, 69);                             // for demonstrating the insertion of one vector into another
    fan.insert(fan.begin() + 1, fin.begin(), fin.end() - 2); // 1: place at which values will be inserted in dest vector; 2:,3: [start,end) range of the source vector

    int x = 50;
    fan.insert(fan.begin() + 2, {30, 40, x, 60});
    for (int x : fan)
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    // // emplace will work like the insert, but in a different way. It has two types of parameter. First is location, rest all are the elements
    fin.emplace(fin.begin() + 1, 45);
    // fin.emplace(fin.begin(), 2, 87); // wont work
    // fan.emplace(fan.begin() + 1, 3, fin.begin(), fin.end() - 2); // wont work

    //.swap()

    // .reverse() OR .sort() WILL NOT WORK

    // 2D vectors
    std::vector<std::vector<int>> vect2d{{1, 2}, {3, 4, 5}, {6}}; // unlike 2d arr, 2dVectors can have different columns
    for (std::vector<int> row : vect2d)                           // for(int i = 0; i < vect2d.size(); i++)
    {
        for (int x : row) // for(int j = 0; j < vect2d[i].size(); j++)
        {
            std::cout << x << " ,"; // x === vect2d[i][j]
        }
        std::cout << std::endl;
    }

    // Vector resize: Shrinks(DOES NOT drops from right, just shifts the end ptr, if resizing shrinks) or increases Vector.resize(size [, default_value])
    // Doesnot destroys the element. Elements still exist, and can be accessible by the indexing. Capacity is max of old and new
    Vector.resize(15);  // resizing with the default value of '0' ZERO
    Vector.resize(20, 96);  // resizing along with the default values
    std::cout << Vector.end() - Vector.begin() << ", " << Vector.capacity() << std::endl;
    Vector.resize(3);
    std::cout << Vector.end() - Vector.begin() << ", " << Vector.capacity() <<  std::endl;

    //Vector.shrink_to_fit(): just destroys the everything after the current size. extra elements. Makes capacity=size.
    // If elements are being tried to be accessed via indexing, it cant be accessed, or maybe show undefined behaviour if get that memory location gets accessed.
    Vector.shrink_to_fit();
    std::cout << Vector.end() - Vector.begin() << ", " << Vector.capacity() << std::endl;

    // Thats how erase work. It can take one position iterator, or range of position iterator; returns itr next to the last element which is actually deleted
    Vector.erase(Vector.begin());
    Vector.erase(Vector.begin(), Vector.end()-1);
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
    m1.emplace(8, 56);  // emplace works as emp[lace for pair
    m1.insert({3,68});  // insert works as insert for pair

    m1.begin(); m1.end(); // they both work here also
    auto itr = m1.find(36); // returns m1.end(); else,if found, returns the pointer to that element

    // upper|lower_bound(<key>) will work. It WILL NOT take value as the parameter. It will take KEY as parameter


    // if pair is the key
    std::map<std::pair<int, int>, int> PairAsKey;
    PairAsKey[{4,6}] = 69;

    

    // since it is ordered map, hence keys will be stored in sorted order. first and second are used for key and value
    std::map<char, int> cnt; // for frequency
    std::string name = "sharan jaiswal";
    for (char c : name)
        cnt[c]++;

    std::cout << cnt['a'] << " " << cnt['s'] << std::endl;

    // find and erase also works. m1.find(<key>) (returns iterators of that element if present, otherwise the .end());
    //  m1.erase(<key>);
    // m1.count(<key>) is used to check the prescence of the key val pair in the map conatiner; returns bool value

    std::multimap<int, int> blah;   // stores in ordered fashion. Also allowes duplicate values
}

void unordered_map()
{
    // unordered map O(1)
    // codeforces divide array in two with equal sum; only one pair swap is allowed
    // Output: Yes/No

    int n;
    std::cin >> n;
    std::vector<int> A(n, 0); // Vector of size 'n' is initialized with '0'.

    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    long long sum = 0; // totla sum of the vector
    for (int &x : A)
        sum += x;

    if (sum & 1)
    {
        std::cout << "No" << std::endl;
        return;
    }

    std::map<int, int> first, second;
    first[A[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        second[A[i]]++;
    }

    long long sumFirst = 0;
    for (int i = 0; i < n; i++)
    {
        sumFirst += A[i]; // sum of first i numbers
        if (sumFirst = sum / 2)
        {
            std::cout << "Yes" << std::endl;
            return;
        }
        else if (sumFirst < sum / 2)
        {
            long long x = sum / 2 - sumFirst;
            // delete element from second half, and insert in first half
            if (second[x] > 0)
            {
                std::cout << "Yes" << std::endl;
                return;
            }
        }
        else // if sumFirst > sum/2
        {
            long long y = sumFirst - sum / 2;
            if (first[y] > 0)
            {
                std::cout << "Yes" << std::endl;
                return;
            }
        }
        first[A[i + 1]]++;
        second[A[i + 1]]--;
    }
    std::cout << "No" << std::endl;

    // if in range based for loops where we iterate over pairs, auto& [key, value]; auto& kv ==> kv.first|second;
    // or, just by normal iterator, itr->first|second
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

    // VectorDemo();
    
    // SetDemo();

    // MapDemo();

    // unordered_map();

    // SetPairQues();

    return 0;
}