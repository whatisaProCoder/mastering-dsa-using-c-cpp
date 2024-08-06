#include <iostream>

using namespace std;

struct HousingPlot
{
    int length;
    int breadth;
    char *address; //array with pointer
};

/*void fun(struct HousingPlot *r)
{
    r->length=20;
    cout<<"Length  : "<<r->length<<endl;
    cout<<"Breadth : "<<r->breadth<<endl;
}*/

struct HousingPlot* funx() //creating struct HousingPlot in heap
{
    struct HousingPlot *p;
    p=new HousingPlot;
    //p=(struct HousingPlot*)malloc(sizeof(struct HousingPlot)); //in C

    p->length=15;
    p->breadth=7;
    p->address="Newtown, Kolkata";

    return p;
};

int main()
{
    /*struct HousingPlot r={10,5};

    fun(&r);

    cout<<"Length  : "<<r.length<<endl;
    cout<<"Breadth : "<<r.breadth<<endl;*/

    struct HousingPlot *ptr=funx();

    cout<<"Length  : "<<ptr->length<<" m"<<endl;
    cout<<"Breadth : "<<ptr->breadth<<" m"<<endl;
    cout<<"Address : "<<ptr->address<<endl;

    return 0;
}
