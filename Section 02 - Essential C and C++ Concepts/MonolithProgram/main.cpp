#include <iostream>

using namespace std;

int main()
{
    int length=0;
    int breadth=0;

    cout<<"Enter length & breadth: "<<endl;
    cin>>length>>breadth;

    int area=length*breadth;
    int peri=2*(length+breadth);

    cout<<"Area      : "<<area<<endl;
    cout<<"Perimeter : "<<peri<<endl;

    return 0;
}
