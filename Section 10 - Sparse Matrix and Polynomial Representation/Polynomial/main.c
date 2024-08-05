#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    int i;
    printf("Enter number of terms : ");
    scanf("%d",&p->n);
    p->terms=(struct Term *)malloc(p->n*sizeof(struct Term));

    printf("Enter terms...\n");
    for(i=0;i<p->n;i++)
        scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
}

void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n-1;i++)
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
    printf("%dx%d\n",p.terms[i].coeff,p.terms[i].exp);
}

struct Poly * add(struct Poly *p1,struct Poly *p2)
{
    struct Poly *sum;
    int i=0,j=0,k=0; //index-tracker
    sum=(struct Poly *)malloc(sizeof(struct Poly));
    sum->terms=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp>p2->terms[j].exp)
            sum->terms[k++]=p1->terms[i++];
        else if(p1->terms[i].exp<p2->terms[j].exp)
            sum->terms[k++]=p2->terms[j++];
        else //if exponent is same
        {
            sum->terms[k].exp=p1->terms[i].exp; //copying exponent
            sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }
    for(;i<p1->n;i++)
        sum->terms[k++]=p1->terms[i];
    for(;j<p2->n;j++)
        sum->terms[k++]=p2->terms[j];

    sum->n=k;

    return sum;
}

int main()
{
    struct Poly p1,p2,*p3;

    printf("Polynomial [p1]------->\n");
    create(&p1);
    printf("Polynomial [p2]------->\n");
    create(&p2);

    p3=add(&p1,&p2);

    printf("Displaying polynomial [p1]...\n");
    display(p1);
    printf("Displaying polynomial [p2]...\n");
    display(p2);
    printf("Displaying polynomial [p3]...\n");
    display(*p3); //dereferencing

    return 0;
}
