#include <iostream>
#include "Queue.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree()
    {
        root=NULL;
    }
    void createTree();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    //void levelorder(Node *p);
    int height(Node *root);
};

void Tree::createTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Enter root-value: ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int Tree::height(Node *root)
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

int main()
{
    Tree t;
    t.createTree();
    cout<<"Preorder..."<<endl;
    t.preorder(t.root);
    cout<<endl;
    cout<<"Inorder..."<<endl;
    t.inorder(t.root);

    return 0;
}
