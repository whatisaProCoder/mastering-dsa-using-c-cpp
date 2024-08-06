#include <iostream>
#include <stdio.h>

using namespace std;

double e(int x, int n) //Horner's Rule: take common in gen-formula to reduce multiplications
{
    static double s;
    if(n==0)
        return s;
    s=1+x*s/n;
    return e(x, n-1);
}

int main()
{
    printf("%lf", e(1, 10));
    return 0;
}
