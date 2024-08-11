#include <iostream>

using namespace std;
class Engineer
{
    public:
    string specialization;
    void work()
    {
        cout<<"I have specialization in "<<specialization<<endl;

    }        
};
class Youtuber 
{
    public :
        int subscriber;
    
    void contentcreator()
    {
        cout<<"I have a subscriver base of "<<subscriber<<endl;
    }
};

class codeTeacher: public Engineer, public Youtuber
{
    public:
    string name;

    codeTeacher(string name , string special , int subscriber)
    {
        this->name=name;
        this->specialization=special;
        this->subscriber=subscriber;
    }

    void showcase()
    {
        cout<<"My name is "<<name <<endl;
        work();
        contentcreator();
    }
};
int main() {
    codeTeacher sp("satya","cs/it",1000);
    sp.showcase();
    return 0;
}