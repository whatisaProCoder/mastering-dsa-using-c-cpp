#include <iostream>

using namespace std;

struct Rectangle
{
    int length; //4 bytes
    int breadth;//4 bytes
    char x;     //4 bytes allocated, only 1 byte used [process: padding]
};

int main()
{
    struct Rectangle r1={10,5};
    r1.length=15;
    r1.breadth=7;
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    return 0;
}
