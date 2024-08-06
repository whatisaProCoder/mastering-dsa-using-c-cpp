#include <iostream>

using namespace std;

void swapping1(int *x, int *y) //using pointers and address
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void swapping2(int &x, int &y) //using reference (only C++)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int main()
{
    int num1=10, num2=15;

  //swapping1(&num1, &num2);
    swapping2(num1, num2);

    cout<<"First Number  : "<<num1<<endl;
    cout<<"Second Number : "<<num2<<endl;

    return 0;
}
