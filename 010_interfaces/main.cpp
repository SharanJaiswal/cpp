// Interfaces are pure virtual functions. Its likely same as abstract method or interface.
// Basically it helps to define a virtual function in base class that doesnt have an implementation base class, but FORCES sublcass to have its implementation.
// those base class basically contains only templates. and since they dont have body, we cant instantiate them.
// If subclass doesnt have overriding function, we cant even instantiate the subclass. Try it by commenting the whole method of Player, & then look its objects.

#include <iostream>
#include <string>

// In CPP, interface is implemented. Its just a class, with only method, w/o body, acting as virtual
class Printable
{
    public:
        virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    // virtual std::string GetName() = 0;  // making this method as a pure virtual fucntion; hence this class' instance creation is not allowed.
    // You can Check by umcommenting. Remember to then comment the just below line.
    virtual std::string GetName() { return "Entity"; };
    std::string  GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name)
        : m_Name(name) {}
    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    // we cant instantiate the Entity class as it dont have body
    // Entity *e = new Entity();
    // std::cout << e->GetName() << std::endl;

    Entity* e0 = new Player("");
    PrintName(e0);

    Player *p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;

    Entity *entity = p;
    std::cout << entity->GetName() << std::endl;

    Entity *e1 = new Entity();
    PrintName(e1);

    Player *p1 = new Player("Cherno");
    PrintName(p1);

    Entity* e2 = new Entity();
    Player* p2 = new Player("Cherno");

    //below, palyer class will also print Entity when Print is called, because the GetClassName from Entity is inherited from the Entity to the player.
    // you can declare and define Players own GetClassName, and call it by using Player instance.
    // toggle the GetClassName of Player to comment/uncomment to see this efect also.
    Print(e2);
    Print(p2);
    Print(e1);
    Print(p);
    Print(entity);
    Print(p1);

    return 0;
}