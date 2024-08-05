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

int pre(char x) //precedence
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

char *infixToPostfix(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc(sizeof(char)*(len+2)); //+2 for '\0' & '#'

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b*c-d/e";
    push('#'); //just an initial character
    char *postfix=infixToPostfix(infix);

    printf("%s",postfix);

    return 0;
}
