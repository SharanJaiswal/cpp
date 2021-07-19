#include <iostream>
#include <string>

using String = std::string;

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const // adding two vectors. Taking other Vector as input.
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Mult(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator+(const Vector2& other)
    {
        return Add(other);  // or, --> return Vector2(x+other.x, y+other.y);
    }

    Vector2 operator*(const Vector2& other)
    {
        return Mult(other); // or, --> return Vector2(x*other.x, y*other.y);
    }

    // In the above two, normal function can be called from the operator overloading function.
    // Reverse can also be true. That is, the operator function can be called from the normal function

    Vector2 Sub(const Vector2& other) const
    {
        // return *this + other;   // method-1 Using 'this' keyword
        return operator-(other);
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    bool operator==(const Vector2& other) const
    {
        return x==other.x && y==other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        // return !operator==(other);
        // return x!=other.x && y!=other.y;
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    #include "../fileio.h"

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);

    Vector2 result = position.Add(speed);
    std::cout << result.x << ", " << result.y << std::endl;

    Vector2 powerup(1.1f, 1.5f);
    result = position.Add(speed.Mult(powerup)); // too much of clutter. Kinda BAWASIR
    std::cout << result.x << ", " << result.y << std::endl;

    // Another method to execute the immediate above calculation, by the OPERATOR OVERLOADING method.
    // This will make it soothing to read
    result = position + speed * powerup;
    std::cout << result.x << ", " << result.y << std::endl;

    result = position.Sub(speed);
    std::cout << result.x << ", " << result.y << std::endl;

    // Operator overloading << for the Vector2 object type. std::cout doesnot take the Vector2 object type and prints its contents
    // We will thus overload the '<<' operator in ostream, for Vector2 type
    // We will make a function to overload it, defined before the main() function. Comment it whole and see the change in the below line
    std::cout << result << std::endl;

    // Compairing two object by teir attr implicitly, by overloading comparision operator
    if(result == position)
    {
        std::cout << "Equal" << std::endl;
    }
    if(result != position)
    {
        std::cout << "Not Equal" << std::endl;
    }
    
    return 0;
}