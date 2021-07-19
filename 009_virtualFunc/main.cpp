// virtual functions helps to override the methods in subclasses, provided method to be overrided is marked as virtual in base class

#include<iostream>
#include<string>

class Entity
{
    public:
        // virtual std::string GetName() { return "Entity"; }
        std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
    private:
        std::string m_Name;
    public:
        Player(const std::string& name)
            : m_Name(name) {}
// writing the OVERRIDE keyword to the declaration of the overriding method is just a good practice. One can omit it also.
        // std::string GetName() override { return m_Name; }
        std::string GetName() { return m_Name; }
};

// Ignone this below function if reading for the first time. You will get to know its use when it is asked later below somewhere.
void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    #include "../fileio.h"
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;

    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;
    // everything is fine till here

    // concept of polymorphism
    // p is actually Player type. But we are assigning it to the Entity type. So, when virtual keyword and override keyword are commented, and when we call GetName(), Entity's GetName is being called.
    // this happens because we are calling GetName with entity which is of type Entity, irrespective of p is assigned to entity.
    // but when virtual and override keyword are uncommented, V-Table is being generated and stored, thus base class function is overridden based on calling object type.
    Entity* entity = p;
    std::cout << entity->GetName() << std::endl;

    // Now look for the PrintName function function above
    Entity* e1  = new Entity();
    PrintName(e1);

    Player* p1 = new Player("Cherno");
    PrintName(p1);

    // AISA BHEDBAHHV KYU?
    // REASON: we've declared normally our methods. When time comes to call the methods, its going to call whatever method belongs to the type.
    // Here its Entity type even if the object instance of type Player.
    // To overcome this partiality, here's where Virtual function comes in.
    // VF implements Dynamic Dispatch which compiles typically implementsv via V-Tables, which is a table that contains mapping of VF inside our base class.
    // This mapping help to match to the correct overridden function at the runtime.
    // Hence if func need to be overridden, the method of the base class need to be marked as VF.
    // So, maintaining VirTab for a function to be overridden of the base class confirms that if case like this occures, correct mappings can happen.
    // Now, in the Entity class, uncomment virtual keywords prepended the class method GetName and see the output changed.
    return 0;
}