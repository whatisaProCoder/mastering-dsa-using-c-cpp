#include <iostream>

using namespace std;

///Toeplitz Matrix (lecture-155)

class TMatrix
{
private:
    int *A;
    int n;
public:
    TMatrix(int n)
    {
        this->n=n;
        A=new int[2*n-1];
    }
    ~TMatrix()
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

void TMatrix::setValue(int i,int j,int x) //must input everything correctly
{
    if(i<=j) //upper-triangle+diagonal
        A[j-i]=x;
    else if(i>j) //lower-triangle
        A[n+i-j-1]=x;
}

int TMatrix::getValue(int i,int j)
{
    if(i<=j)
        return A[j-i];
    else if(i>j)
        return A[n+i-j-1];
}

void TMatrix::display()
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
    TMatrix matrix(dim);
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
