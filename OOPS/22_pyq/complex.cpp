#include <iostream>

using namespace std;

class complex
{
    double real , img;
    public:
        complex()
        {

        }
        complex operator+( complex &b)
        {
            complex temp;
            temp.real= real+b.real;
            temp.img=img+b.img;
            return temp;
            //return complex(this->real+b.real , this->img +b.img);
        }
        complex(double real, double img)
        {
            this->real=real; this->img=img;
        }
        void display()
        {
            cout<<this->real<<" + "<<this->img<<"i"<<endl;
        }
};

int main() {
    complex a(10, 12);
    complex b(12, 10);
    complex c=a+b;
    c.display();
    return 0;
}

