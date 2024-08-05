#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int A[n];
    cout<<"Enter "<<n<<" elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<<"The array in memory is the following: "<<endl;
    for(int x:A)
    {
        cout<<x<<endl;
    }

    int sum;
    for(int x:A)
    {
        sum+=x;
    }
    cout<<"Sum of elements of the array: "<<sum<<endl;

    return 0;
}
