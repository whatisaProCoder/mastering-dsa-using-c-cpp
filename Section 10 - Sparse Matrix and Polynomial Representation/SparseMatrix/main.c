#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i; //row-number
    int j; //column-number
    int x; //non-zero element
};

struct SparseMatrix
{
    int m; //number of rows
    int n; //number of columns
    int num; //number of non-zero elements
    struct Element *ele; //array of elements
};

void create(struct SparseMatrix *s)
{
    int i;

    printf("Enter dimensions : ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter number of non-zero elements = ");
    scanf("%d",&s->num);

    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));

    printf("Enter the coordinates and the non-zero elements...\n");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
}

void display(struct SparseMatrix s)
{
    int i,j,k=0; //k : keeps track of non-zero elements

    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ",s.ele[k++].x); //k++ : moves to the next element
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct SparseMatrix* add(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
    if(s1->n!=s2->n || s1->m!=s2->m)
        return NULL;

    struct SparseMatrix *sum;
    int i=0,j=0,k=0; //to traverse through s1.ele, s2.ele and sum.ele
    sum=(struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));

    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i<s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++];
        else if(s1->ele[i].i>s2->ele[j].i)
            sum->ele[k++]=s2->ele[j++];
        else
        {
            if(s1->ele[i].j<s2->ele[j].j)
                sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].j>s2->ele[j].j)
                sum->ele[k++]=s2->ele[j++];
            else
            {
                sum->ele[k]=s1->ele[i]; //copying i,j,x from s1.element to sum.element
                sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x; //summation and incrementing i,j,k
            }
        }
    }
    //copying remaining elements
    for(;i<s1->num;i++)
        sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;j++)
        sum->ele[k++]=s2->ele[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k; //k : tracks number of non-zero elements

    return sum;
}

int main()
{
    struct SparseMatrix s1,s2,*s3;

    printf("Matrix [s1]-------->\n");
    create(&s1);
    printf("Matrix [s2]-------->\n");
    create(&s2);

    s3=add(&s1,&s2);

    printf("Displaying the matrix [s1]...\n");
    display(s1);
    printf("Displaying the matrix [s2]...\n");
    display(s2);
    printf("Displaying the matrix [s3]...\n");
    display(*s3);

    return 0;
}
