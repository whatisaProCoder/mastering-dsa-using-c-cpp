#include <iostream>

using namespace std;

///Diagonal Matrix in C++ Class

class DiagonalMatrix
{
private:
    int n;
    int *A;
public:
    DiagonalMatrix(int n)
    {
        this->n=n;
        A=new int[n];
    }
    ~DiagonalMatrix()
    {
        delete []A;
    }
    void setValue(int i,int j,int x);
    int getValue(int i,int j);
    void display();
};

void DiagonalMatrix::setValue(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}

int DiagonalMatrix::getValue(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}

void DiagonalMatrix::display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    DiagonalMatrix d(4);

    d.setValue(1,1,5);
    d.setValue(2,2,8);
    d.setValue(3,3,9);
    d.setValue(4,4,12);

    d.display();

    return 0;
}
