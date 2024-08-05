#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int nodeHeight(struct Node *p)
{
    int hl,hr;
    hl=(p && p->lchild)?p->lchild->height:0;
    hr=(p && p->rchild)?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int balanceFactor(struct Node *p)
{
    int hl,hr;
    hl=(p && p->lchild)?p->lchild->height:0;
    hr=(p && p->rchild)?p->rchild->height:0;

    return hl-hr;
}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);

    if(p==root)
        root=pl;

    return pl;
}

struct Node * LRRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    plr->height=nodeHeight(plr);

    if(p==root)
        root=plr;

    return plr;
}

struct Node * RRRotation(struct Node *p)
{
    return NULL; //later
}

struct Node * RLRotation(struct Node *p)
{
    return NULL; //later
}

struct Node * rinsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->height=1; //starting from one
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rinsert(p->rchild,key);

    p->height=nodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->lchild)==-1)
        return RRRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
        return RLRotation(p);


    return p;
}

int main()
{
    root=rinsert(root,50);
    rinsert(root,10);
    rinsert(root,20);
    return 0;
}
