#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL; //declaring Node-type pointer globally

void create(int A[],int n)
{
    int i;
    struct Node *t;
    struct Node *last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first; //important

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t; //before : last=first, so actually its : first->next=t
        last=t;       //new node(t) is the last node
    }
}

void create2(int A[],int n)
{
    int i;
    struct Node *t;
    struct Node *last;

    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second; //important

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t; //before : last=first, so actually its : first->next=t
        last=t;       //new node(t) is the last node
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void rdisplay(struct Node *p) //displaying recursively
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        rdisplay(p->next);
        //printf("%d ",p->data); //prints while returning; in reverse-order
    }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int rcount(struct Node *p) //using recursion
{
    if(p!=NULL)
        return rcount(p->next)+1;
    else
        return 0;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int rsum(struct Node *p) //recursively
{
    if(p==NULL)
        return 0;
    else
        return rsum(p->next)+p->data;
}

int max(struct Node *p)
{
    int max=INT_MIN;

    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

int rmax(struct Node *p) //recursively
{
    int x=0;
    if(p==0)
        return INT_MIN;
    x=rmax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

struct Node * linearsearch(struct Node *p,int key)
{
    //move to front operation =>    //**//
    struct Node *q;                 //**//
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;        //**//
            p->next=first;          //**//
            first=p;                //**//
            return p;
        }
        q=p;                        //**//
        p=p->next;                  //**//
    }
    return NULL;
}

struct Node * rlinearsearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return rlinearsearch(p->next,key);

}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index<0 || index>count(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
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

void sortedinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL) //if list is empty
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int deleteNode(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index<1 || index>count(p))
        return x;

    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(p);
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
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x=INT_MIN;

    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void removeDuplicates(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }

    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q=NULL;
    struct Node *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r; //critical for reversing
    }
    first=q;
}

void reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void concat(struct Node *p,struct Node *q)
{
    third=p;

    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void merge(struct Node *p,struct Node *q) //sorts in the process
{
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
}

int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    /*
    int A[]={50,40,10,30,20};
    create(A,5);
    */

    /*
    display(first);
    printf("Length : %d\n",count(first));
    printf("Sum    : %d\n",sum(first));
    printf("Max    : %d\n",rmax(first));
    */

    /*
    struct Node *temp;
    temp=linearsearch(first,25);
    temp=linearsearch(first,8);
    if(temp!=NULL)
        printf("Key [%d] is found.\n",temp->data);
    else
        printf("Key is not found.\n");
    printf("Linked List Data...\n");
    display(first);
    */

    /*
    insert(first,0,10);
    insert(first,1,20);
    insert(first,2,30);
    insert(first,0,5);
    display(first);
    */

    /*
    display(first);
    printf("\n");
    sortedinsert(first,55);
    display(first);
    */

    /*
    printf("Deleted Element : %d\n",deleteNode(first,2));
    display(first);
    */

    /*
    printf("isSorted() { returns : %d (%s) }\n",isSorted(first),
           isSorted(first)==1?"true":"false");
    */

    /*
    removeDuplicates(first);
    display(first);
    */

    /*
    //reverse2(first);
    reverse3(NULL,first);
    display(first);
    */

    /*
    int A[]={10,20,30,40,50};
    int B[]={5,15,25,35,45};
    create(A,5);
    create2(B,5);

    printf("First Linked-List...\n");
    display(first);
    printf("\n");
    printf("Second Linked-List...\n");
    display(second);
    printf("\n");
    merge(first,second);
    printf("Merged Linked-List...\n");
    display(third);
    printf("\n");
    */

    struct Node *t1,*t2;
    int A[]={10,20,30,40,50};
    create(A,5);

    t1=first->next->next; //points on node:30
    t2=first->next->next->next->next; //points on node:50
    t2->next=t1; //becomes a loop

    printf("isLoop() { returns %d }\n",isLoop(first));

    return 0;
}
