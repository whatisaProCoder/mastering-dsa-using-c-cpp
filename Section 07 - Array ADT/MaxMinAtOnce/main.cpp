#include <iostream>

using namespace std;

int main()
{
    int i,n=10,min,max;
    int A[n]={5,8,3,9,6,2,10,7,-1,4};
    max=A[0];
    min=A[0];

    for(i=1;i<n;i++) //i=1 since max=A[0],min=A[0]
    {
        if(max<A[i])
            max=A[i];
        if(min>A[i])
            min=A[i];
    }
    printf("Maximum : %d\nMinimum : %d",max,min);

    return 0;
}
