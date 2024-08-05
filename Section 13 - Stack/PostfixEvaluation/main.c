#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
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

int pop()
{
    struct Node *t;
    int x=-1;
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

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int evaluate(char *postfix)
{
    int i=0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop();
            x1=pop();
            switch(postfix[i])
            {
            case '+':
                r=x1+x2;
                break;
            case '-':
                r=x1-x2;
                break;
            case '/':
                r=x1/x2;
                break;
            case '*':
                r=x1*x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix="234*+82/-";

    printf("Result: %d",evaluate(postfix));

    return 0;
}
