#include <iostream>

using namespace std;

///Lower Triangular Matrix in C++ Class

class LowerTriangularMatrix
{
private:
    int *A;
    int n;
public:
    LowerTriangularMatrix(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2]; //see lecture-147
    }
    ~LowerTriangularMatrix()
    {
        delete []A;
    }
    int getDimension()
    {
        return n;
    }
    void setValue_ROWMAJOR(int i,int j,int x);
    void setValue_COLUMNMAJOR(int i,int j,int x);
    int getValue_ROWMAJOR(int i,int j);
    int getValue_COLUMNMAJOR(int i,int j);
    void display_ROWMAJOR();
    void display_COLUMNMAJOR();
};

void LowerTriangularMatrix::setValue_ROWMAJOR(int i,int j,int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x; //see lecture-147
}

void LowerTriangularMatrix::setValue_COLUMNMAJOR(int i,int j,int x)
{
    if(i>=j)
        A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x; //see lecture-148
}

int LowerTriangularMatrix::getValue_ROWMAJOR(int i,int j)
{
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}

int LowerTriangularMatrix::getValue_COLUMNMAJOR(int i,int j)
{
    if(i>=j)
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    else
        return 0;
}

void LowerTriangularMatrix::display_ROWMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

void LowerTriangularMatrix::display_COLUMNMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int i,j,x,dim;
    cout<<"Enter dimension : ";
    cin>>dim;
    cout<<"Enter all elements :"<<endl;
    LowerTriangularMatrix m(dim);
    for(i=1;i<=m.getDimension();i++)
    {
        for(j=1;j<=m.getDimension();j++)
        {
            cin>>x;
            m.setValue_ROWMAJOR(i,j,x);
        }
    }

    cout<<"The matrix becomes..."<<endl;
    m.display_ROWMAJOR();

    return 0;
}
