#include <iostream>

using namespace std;

void fun(int n)
{
    if(n>0)
    {
        cout<<"Tail recursion; n="<<n<<endl;
        fun(n-1);
        cout<<"Head recursion; n="<<n<<endl;
    }
}

int main()
{
    int x=5;
    fun(x);

    return 0;
}
