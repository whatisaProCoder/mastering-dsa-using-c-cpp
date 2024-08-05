#include <iostream>

using namespace std;

int fun(int n)
{f
    if(n>100)
        return n-10;
    return fun(fun(n+11));
}

int main()
{
    int r;
    r=fun(30);
    cout<<"Result : "<<r;
    return 0;
}
