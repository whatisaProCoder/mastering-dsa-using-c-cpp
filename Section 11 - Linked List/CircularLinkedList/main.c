#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head; //making it circular
    last=Head;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next; //circular
        last->next=t;
        last=t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    } while(h!=Head);
    printf("\n");
}

void rdisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        rdisplay(h->next);
    }
    flag=0;
}

int length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    } while(p!=Head);
    return len;
}

void insertNode(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index<0 || index>length(p))
        return;

    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while(p->next!=Head)
                p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int deleteNode(struct Node *p,int index)
{
    struct Node *q;
    int i,x=-1;

    if(index<0 || index>length(p))
        return x;
    if(index==1)
    {
        while(p->next!=Head)
            p=p->next;
        x=Head->data;
        if(Head==p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    //insertNode(Head,5,10);
    deleteNode(Head,5);

    rdisplay(Head);

    return 0;
}
