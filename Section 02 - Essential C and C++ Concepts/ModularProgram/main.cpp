#include <iostream>

using namespace std;

int area(int length, int breadth)
{
    return length*breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p=2*(length+breadth);
    return p;
}

int main()
{
    int length=0;
    int breadth=0;

    cout<<"Enter length & breadth: "<<endl;
    cin>>length>>breadth;

    int a=area(length, breadth);
    int p=perimeter(length, breadth);

    cout<<"Area      : "<<a<<endl;
    cout<<"Perimeter : "<<p<<endl;

    return 0;
}
