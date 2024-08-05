#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack Overflow\n"); //if heap-memory is full, t is not created
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop()
{
    struct Node *t;
    char x=-1;
    if(top==NULL)
        printf("Stack Underflow\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL) //checking if stack if empty
                return 0;
            pop();
        }
    }
    if(top==NULL) //checking if stack if empty
        return 1;
    else
        return 0;
}

int isBalancedAdv(char *exp)
{
    int i;
    char x;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==NULL)
                return 0;
            x=pop();
            if(!((x=='(' && exp[i]==')')||
                 (x=='{' && exp[i]=='}')||
                 (x=='[' && exp[i]==']')))
               return 0;
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    /*
    char *exp="((a+b)*(c-d))";
    printf("isBalanced() => %d\n",isBalanced(exp));
    */

    char *exp="{([a+b]*[c-d])/e}";
    printf("isBalancedAdv() => %d\n",isBalancedAdv(exp));
}
