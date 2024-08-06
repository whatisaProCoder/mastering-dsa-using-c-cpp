#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList(){first=NULL;}
    LinkedList(int A[],int n);
    ~LinkedList();
    void display();
    void insertNode(int index,int x);
    int deleteNode(int index);
    int length();
};

LinkedList::LinkedList(int A[],int n)
{
    int i;
    Node *t;
    Node *last;

    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first; //important

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t; //before : last=first, so actually its : first->next=t
        last=t;       //new node(t) is the last node
    }
}

LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::display()
{
    Node *p=first;

    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int LinkedList::length()
{
    Node *p=first;
    int len=0;

    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void LinkedList::insertNode(int index,int x)
{
    Node *t,*p=first;
    int i;

    if(index<0 || index>length())
        return;

    t=new Node;
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int LinkedList::deleteNode(int index)
{
    Node *q=NULL,*p=first;
    int x=-1,i;

    if(index<1 || index>length())
        return x;

    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete p;
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);

    l.display();
    //cout<<"Length : "<<l.length()<<endl;
    //cout<<"Deleted Element : "<<l.deleteNode(3)<<endl;
    l.insertNode(3,10);
    l.display();
    return 0;
}
