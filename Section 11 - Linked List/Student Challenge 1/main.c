#include <stdio.h>
#include <stdlib.h>

///Student Challenge : Finding Middle Element of a Linked List.

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *last;
    struct Node *t;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int middleElement(struct Node *f)
{
    struct Node *p=f;
    struct Node *q=f;

    while(q)
    {
        q=q->next;
        if(q)
        {
            q=q->next;
            p=p->next;
        }
    }
    return p->data;
}

int main()
{
    int A[]={11,22,33,44,55,66,77,88,99};
    create(A,9);
    display(first);

    printf("Middle Element: %d",middleElement(first));

    return 0;
}
