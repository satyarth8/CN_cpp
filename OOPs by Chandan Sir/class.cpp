#include <iostream>

using namespace std;
// Write a simple program using class in C++ to input subject mark and prints it
class student{
    private:
    int mark_sub1;
    int mark_sub2;
    public:
    void get_data();
    void put_data();
};
void student:: get_data()
{
    cout<<"enter sub1 marks"<<endl;
    cin>>mark_sub1;
    cout<<"enter sub2 marks"<<endl;
    cin>>mark_sub2;
}
void student:: put_data()
{
    cout<<mark_sub1<<endl;
    cout<<mark_sub2;
}
int main() {
    student satyarth;
    satyarth.get_data();
    satyarth.put_data();
    return 0;
}