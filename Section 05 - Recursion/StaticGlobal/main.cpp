#include <iostream>

using namespace std;

int x;

int fun(int n)
{
    //static int x;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int r;

    r=fun(5);
    cout<<"Result : "<<r<<endl;

    r=fun(5);
    cout<<"Result : "<<r;

    return 0;
}
