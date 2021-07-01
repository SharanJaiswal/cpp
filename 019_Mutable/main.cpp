// HALF PART OF THIS VIDEO LECTURE WHICH CONTAINS TOPICS ABOUT LAMBDA IS NOT COVERED HERE DUE TO :(

#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0;   // marking this attributes mutable ensures that const methods inside this class can modify this variable
    public:
        const std::string& GetName() const  // check how the removal of const keyword, makes instantiation of constant Entity object 'e' invalid, in the first line of main()
        {
            m_DebugCount++;
            return m_Name;
        }
};

int main()
{
    const Entity e;
    e.GetName();
    return 0;
}