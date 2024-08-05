#include <iostream>

using namespace std;

int main()
{
    int A[3][4]= {{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int i,j;

    cout<<"Array - A :"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    } cout<<endl;

    int *B[3];
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    cout<<"Array - B :"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            cout<<B[i][j]<<" ";
        cout<<endl;
    } cout<<endl;

    int **C;
    C=(int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    cout<<"Array - C :"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
