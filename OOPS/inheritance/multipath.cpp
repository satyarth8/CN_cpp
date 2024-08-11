#include <iostream>

using namespace std;

class human
{
    public:
    string name;

    void display()
    {
        cout<<"my name is"<<name<<endl;
    }
};
class Engineer : public virtual human
{
    public:
        string specialization;

        void work()
        {
            cout<<"\nI have specialization in "<<specialization<<endl;
        }
};
class Youtuber : public virtual human 
{
    public:
         int sub_count;
         void contentcreator()
         {
            cout<<"\nI have a subscriber base of "<<sub_count<<endl;
         }
};

class CodeTeacher: public Youtuber , public Engineer
{
    public:
    int salary;

    CodeTeacher(string name, string specialization , int sub_count, int salary)
    {
        this->salary=salary;
        this->name=name;
        this->specialization=specialization;
        this->sub_count=sub_count;
    }

    void showcase()
    {
        cout<<"\nName: "<<name;
        work();
        contentcreator();
    }
};

int main() {
    CodeTeacher sp("Satya","C++",100,1000);
    sp.showcase();
    return 0;
}