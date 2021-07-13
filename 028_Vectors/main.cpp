// vectors are stored on heap memory
// copying is done with vectors of objects, but not with vectors of pointers, to store new entry when they get filled up

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex& vertex)    // copy constructor
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices) {}   // const is optional, but a good practice if no manipulation is done



struct OptVertex
{
    float x, y, z;
    OptVertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }
    OptVertex(const OptVertex& optver)
        :x(optver.x), y(optver.y), z(optver.z)
        {
            std::cout << "Copied in OptVer!" << std::endl;
        }
};

std::ostream& operator<<(std::ostream& stream, const OptVertex& optver)
{
    stream << optver.x << ", " << optver.y << ", " << optver.z;
    return stream;
}

void Function(const std::vector<OptVertex>& optver) {}



int main()
{
    #include "../fileio.h"
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});
    for(int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] <<std::endl;
    }
    for(Vertex v : vertices)    // Rnage based index. However it is copying the data
    {
        std::cout << v << std::endl;
    }

    // vertices.clear();   // flushes all the enetred elements.
    std::cout << "Size: " << vertices.size() << ", Capacity: " << vertices.capacity() << std::endl;

    vertices.erase(vertices.begin() + 1);   // takes iterator, not just randomly a number as an index eg, 0, 1, 2, 3 (DONT USES THESE)
    for(Vertex& v : vertices)   // Not copying is done. Still Similar result.
    {
        std::cout << v << std::endl;
    }

    // PASSING VECTORS TO A FUNCTION.
    // Always pass by reference. Thats it. It is less costly
    Function(vertices);

// Even when we are trying to push an element{1,2,3} to the vector Vertex, we are observing that a copy constructor is being called.
// This is happening because, initially, we are actually constructing it in the current stack frame of the main() function.
// Later, this will get transferred to the actual Vertex vector, and this happens via the COPYING. Hence, copy constructor is being called.
// We also observe that, everytime when capacity of vector doubles, <size> number of copies again happen, then new element gets added via its own copying
    vertices.push_back({7,8,9});
    vertices.push_back(Vertex(10, 11, 12));
    vertices.push_back(Vertex(13, 14, 15));
// We can do two optimizations. First, we could directly push Vertex vector element to Vertex vector;
// Second, if we know vaguely the least amount of element that will be present in any case, then we can avoid the resizing and copying due to resizing of the vector.
// We will just initialize the vector from that minimum size.

// lets acheive this with new vector type
std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

    std::vector<OptVertex> optver; // std::vector<OptVertex> optver(3); it will actuallu make three OptVertex objects
    optver.reserve(3);  // Its actually going to reserve the space for 3 OptVertex object, but not yet initialize them
    optver.push_back(OptVertex(99,88,77));
    optver.push_back(OptVertex(66,55,44));
    optver.push_back(OptVertex(33,22,11));  // only 3 copies till now
// If now a single element is being pushed back to the optver vector, then total 7 copies will be shown
    optver.clear();
// We can furthue optimize by constructing the elelemnts in vector itself
std::cout << "EMPLACING for constructing object in vector itself discards copying." << std::endl;
    optver.emplace_back(1,2,3);
    optver.emplace_back(4,5,6);
    optver.emplace_back(7,8,9);
std::cout << "0 copying done for first 3 elements pushed, rather EMPALCED" << std::endl;

    return 0;
}