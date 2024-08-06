#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;

    int area()
    {
        return length*breadth;
    }

    int perimeter()
    {
        int p;
        p=2*(length+breadth);
        return p;
    }

    void initialise(int l, int b)
    {
        length=l;
        breadth=b;
    }

}; //semi-colon required

int main()
{
    Rectangle r;

    int l, b;
    cout<<"Enter length & breadth: "<<endl;
    cin>>l>>b;

    r.initialise(l, b);

    int a=r.area();
    int p=r.perimeter();

    cout<<"Area      : "<<a<<endl;
    cout<<"Perimeter : "<<p<<endl;

    return 0;
}
