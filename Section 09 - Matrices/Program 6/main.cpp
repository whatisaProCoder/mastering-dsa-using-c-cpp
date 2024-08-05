#include <iostream>

using namespace std;

///Symmetric Matrix in C++ Class

class SymmetricMatrix //Deriving from LowerTriangularMatrix Class
{
private:
    int *A;
    int n;
public:
    SymmetricMatrix(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2]; //see lecture-147
    }
    ~SymmetricMatrix()
    {
        delete []A;
    }
    int getDimension()
    {
        return n;
    }
    void swapping(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void setValue_ROWMAJOR(int i,int j,int x);
    void setValue_COLUMNMAJOR(int i,int j,int x);
    int getValue_ROWMAJOR(int i,int j);
    int getValue_COLUMNMAJOR(int i,int j);
    void display_ROWMAJOR();
    void display_COLUMNMAJOR();
};

void SymmetricMatrix::setValue_ROWMAJOR(int i,int j,int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x; //see lecture-147
    else
    {
        swapping(&i,&j);
        A[i*(i-1)/2+j-1]=x;
    }
}

void SymmetricMatrix::setValue_COLUMNMAJOR(int i,int j,int x)
{
    if(i>=j)
        A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x; //see lecture-148
    else
    {
        swapping(&i,&j);
        A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
    }
}

int SymmetricMatrix::getValue_ROWMAJOR(int i,int j)
{
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    else
    {
        swapping(&i,&j);
        return A[i*(i-1)/2+j-1];
    }
}

int SymmetricMatrix::getValue_COLUMNMAJOR(int i,int j)
{
    if(i>=j)
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    else
    {
        swapping(&i,&j);
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    }
}

void SymmetricMatrix::display_ROWMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
            {
                swapping(&i,&j);
                cout<<A[i*(i-1)/2+j-1]<<" ";
                swapping(&i,&j);
            }
        }
        cout<<endl;
    }
}

void SymmetricMatrix::display_COLUMNMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
            else
            {
                swapping(&i,&j);
                cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
                swapping(&i,&j);
            }
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
    SymmetricMatrix m(dim);
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
