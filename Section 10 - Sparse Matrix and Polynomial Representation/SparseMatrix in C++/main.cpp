#include <iostream>

using namespace std;

class Element
{
public:
    int i; //row-number
    int j; //column-number
    int x; //non-zero element
};

class SparseMatrix
{
private:
    int m; //number of rows
    int n; //number of columns
    int num; //number of non-zero elements
    Element *ele; //array of elements
public:
    SparseMatrix(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new Element[this->num];
    }
    ~SparseMatrix()
    {
        delete []ele;
    }
    //interesting...
    SparseMatrix operator+(SparseMatrix &s);
    friend istream & operator>>(istream &is,SparseMatrix &s);
    friend ostream & operator<<(ostream &os,SparseMatrix &s);
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s)
{
    if(n!=s.n || m!=s.m)
        return SparseMatrix(0,0,0);

    int i=0,j=0,k=0; //to traverse through s1.ele, s2.ele and sum.ele
    SparseMatrix *sum=new SparseMatrix(m,n,num+s.num);
    sum->ele=new Element[num+s.num];

    while(i<num && j<s.num)
    {
        if(ele[i].i<s.ele[j].i)
            sum->ele[k++]=ele[i++];
        else if(ele[i].i>s.ele[j].i)
            sum->ele[k++]=s.ele[j++];
        else
        {
            if(ele[i].j<s.ele[j].j)
                sum->ele[k++]=ele[i++];
            else if(ele[i].j>s.ele[j].j)
                sum->ele[k++]=s.ele[j++];
            else
            {
                sum->ele[k]=ele[i]; //copying i,j,x from s1.element to sum.element
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x; //summation and incrementing i,j,k
            }
        }
    }
    //copying remaining elements
    for(;i<num;i++)
        sum->ele[k++]=ele[i];
    for(;j<s.num;j++)
        sum->ele[k++]=s.ele[j];
    sum->num=k; //k : tracks number of non-zero elements

    return *sum; //dereferencing : from pointer to actual object
}

istream & operator>>(istream &is,SparseMatrix &s)
{
    int i;

    printf("Enter the coordinates and the non-zero elements...\n");
    for(i=0;i<s.num;i++)
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;

    return is;
}

ostream & operator<<(ostream &os,SparseMatrix &s)
{
    int i,j,k=0; //k : keeps track of non-zero elements

    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
                cout<<s.ele[k++].x<<" "; //k++ : moves to the next element
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

int main()
{
    SparseMatrix s1(5,5,5);
    SparseMatrix s2(5,5,5);

    cout<<"Matrix [s1]-------->"<<endl;
    cin>>s1; //reading input for s1

    cout<<"Matrix [s2]-------->"<<endl;
    cin>>s2; //reading input for s2

    SparseMatrix sum=s1+s2;

    cout<<"Displaying the matrix [s1]....\n"<<s1;
    cout<<"Displaying the matrix [s2]....\n"<<s2;

    cout<<"Displaying the matrix [sum]...\n"<<sum;

    return 0;
}

