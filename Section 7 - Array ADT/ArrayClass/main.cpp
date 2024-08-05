#include <iostream>

using namespace std;

template<class T>
class Array
{
private:
    T *A;
    int sz;
    int length;
public:
    Array()
    {
        sz=10;
        A=new T[sz];
        length=0;
    }
    Array(int sz)
    {
        this->sz=sz;
        A=new T[sz];
        length=0;
    }
    ~Array()
    {
        delete []A;
    }
    void Display();
    void Insert(int index,T x);
    T Delete(int index);
};

template<class T>
void Array<T>::Display()
{
    int i;
    cout<<"Elements are :\n";
    for(i=0; i<length; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index,T x)
{
    int i;
    if(index>=0 && index<=length)
    {
        for(i=length; i>index; i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
    int i;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index; i<length-1; i++)
            A[i]=A[i+1];
        length--;
        return x;
    }
    return -1; //nothing to delete
}

int main()
{
    Array<char> arr(10);
    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}
