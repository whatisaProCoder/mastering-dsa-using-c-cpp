#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;

    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

struct Node * search(int key)
{
    struct Node *t=root;

    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

struct Node * rinsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rinsert(p->rchild,key);
    return p;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

struct Node * inorderPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;

    return p;
}

struct Node * inorderSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;

    return p;
}

struct Node * delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inorderPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);
        }
        else
        {
            q=inorderSucc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    root=rinsert(root,10);
    rinsert(root,5);
    rinsert(root,20);
    rinsert(root,8);
    rinsert(root,30);

    delete(root,20);

    inorder(root);
    printf("\n");

    struct Node *temp=search(20);
    if(temp!=NULL)
        printf("Element [%d] is found...\n",temp->data);
    else
        printf("Element is not found...\n");

    return 0;
}
