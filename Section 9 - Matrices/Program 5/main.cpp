#include <iostream>

using namespace std;

///Upper Triangular Matrix in C++ Class

class UpperTriangularMatrix
{
private:
    int *A;
    int n;
public:
    UpperTriangularMatrix(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2]; //see lecture-151
    }
    ~UpperTriangularMatrix()
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

//n*(i-1)-(i-2)*(i-1)/2+j-i (ROWMAJOR-Formula, similar to LTM's COLUMNMAJOR-Formula)
//j*(j-1)/2+i-1             (COLUMNMAJOR-Formula, similar to LTM's ROWMAJOR-Formula)

void UpperTriangularMatrix::setValue_ROWMAJOR(int i,int j,int x)
{
    if(i<=j)
        A[n*(i-1)-(i-2)*(i-1)/2+j-i]=x; //see lecture-151
}

void UpperTriangularMatrix::setValue_COLUMNMAJOR(int i,int j,int x)
{
    if(i<=j)
        A[j*(j-1)/2+i-1]=x; //see lecture-152
}

int UpperTriangularMatrix::getValue_ROWMAJOR(int i,int j)
{
    if(i<=j)
        return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
    else
        return 0;
}

int UpperTriangularMatrix::getValue_COLUMNMAJOR(int i,int j)
{
    if(i<=j)
        return A[j*(j-1)/2+i-1];
    else
        return 0;
}

void UpperTriangularMatrix::display_ROWMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[n*(i-1)-(i-2)*(i-1)/2+j-i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

void UpperTriangularMatrix::display_COLUMNMAJOR()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[j*(j-1)/2+i-1]<<" ";
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
    UpperTriangularMatrix m(dim);
    for(i=1;i<=m.getDimension();i++)
    {
        for(j=1;j<=m.getDimension();j++)
        {
            cin>>x;
            //m.setValue_ROWMAJOR(i,j,x);
            m.setValue_COLUMNMAJOR(i,j,x);
        }
    }

    cout<<"The matrix becomes..."<<endl;
    //m.display_ROWMAJOR();
    m.display_COLUMNMAJOR();

    return 0;
}
