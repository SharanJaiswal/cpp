// Anything that is not private in base class, is being accessed by the chile class

#include<iostream>

class Entity
{
    public:
        float X,Y;
        void Move(float x, float y)
        {
            X += x;
            Y += y;
        }
};

class Player : public Entity
{
    public:
        const char* Name;
        void PrintName(void)
        {
            std::cout << Name << std::endl;
        }
};

int main()
{
    std::cout << sizeof(Entity) << ", " << sizeof(Player) << std::endl;
    Player player;
    player.PrintName();
    player.Move(5.0f, 5.0f);
    player.X;
    player.Y;
    return 0;
}