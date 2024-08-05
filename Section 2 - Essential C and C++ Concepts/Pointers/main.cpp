#include <iostream>
#include <stdio.h> //to use printf()
#include <stdlib.h>
using namespace std;

void example1() //assigning integer variable to pointer
{
    int a=10;
    int *p;
    p=&a;

    cout<<"Value(a)      : "<<a<<endl;
    printf("Using pointer : %d", *p); //dereferencing
}

void example2() //assigning array to pointer in stack memory
{
    int A[5]={2,4,6,8,10};
    int *p;
    p=A;

    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }
}

void example3() //assigning array to pointer in heap memory
{
    int *p;
  //p=(int *)malloc(5*sizeof(int)); //malloc() must in C for heap allocation
    p=new int[5]; //new instead of malloc() in C++

    p[0]=10; p[1]=15; p[2]=14; p[3]=21; p[4]=31;

    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }

  //free(p);    //deleting from heap in C
    delete []p; //deleting from heap in C++
}

struct Rectangle
{
    int length;
    int breadth;
};

void example4()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
}

int main()
{
    example4();

    return 0;
}
