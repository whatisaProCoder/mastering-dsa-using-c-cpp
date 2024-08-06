#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle r)
{
    return r.length*r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p=2*(r.length+r.breadth);
    return p;
}

void initialise(struct Rectangle *r, int l, int b)
{
    r->length=l;
    r->breadth=b;
}

int main()
{
    struct Rectangle r={0,0};

    int l, b;
    cout<<"Enter length & breadth: "<<endl;
    cin>>l>>b;

    initialise(&r, l, b);

    int a=area(r);
    int p=perimeter(r);

    cout<<"Area      : "<<a<<endl;
    cout<<"Perimeter : "<<p<<endl;

    return 0;
}
