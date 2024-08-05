#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void objInStack()
{
    Rectangle r={10,5}; //struct Rectangle required in C
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
}

void objInHeap()
{
    Rectangle *p;
  //p=(struct Rectangle *)malloc(sizeof(struct Rectangle)); //in C
    p=new Rectangle; //in C++

    p->length=15;
    p->breadth=7;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
}

int main()
{
    objInHeap();
    return 0;
}
