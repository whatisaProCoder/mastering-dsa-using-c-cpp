#include <iostream>

using namespace std;

///Tri-diagonal Matrix (lecture-154)

class TDMatrix
{
private:
    int *A;
    int n;
public:
    TDMatrix(int n)
    {
        this->n=n;
        A=new int[3*n-2];
    }
    ~TDMatrix()
    {
        delete []A;
    }
    int getDimension()
    {
        return n;
    }
    void setValue(int i,int j,int x); //i,j indices start from <1>
    int getValue(int i,int j);
    void display();
};

void TDMatrix::setValue(int i,int j,int x)
{
    if(i-j==1)
        A[i-2]=x;
    else if(i-j==0)
        A[n-1+i-1]=x;
    else if(i-j==-1)
        A[2*n-1+i-1]=x;
}

int TDMatrix::getValue(int i,int j)
{
    if(i-j==1)
        return A[i-2];
    else if(i-j==0)
        return A[n-1+i-1];
    else if(i-j==-1)
        return A[2*n-1+i-1];
    else
        return 0;
}

void TDMatrix::display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<getValue(i,j)<<" "; //shortcut
        }
        cout<<endl;
    }
}

int main()
{
    int i,j,x,dim;
    cout<<"Enter dimension : ";
    cin>>dim;
    TDMatrix matrix(dim);
    cout<<"Enter elements :"<<endl;
    for(i=1;i<=matrix.getDimension();i++)
    {
        for(j=1;j<=matrix.getDimension();j++)
        {
            cin>>x;
            matrix.setValue(i,j,x);
        }
    }
    cout<<"The matrix becomes..."<<endl;
    matrix.display();

    return 0;
}
