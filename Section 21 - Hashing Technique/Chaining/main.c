#include <stdio.h>
#include <stdlib.h>
#include "Chains.h"

int hash(int key)
{
    return key%10;
}

void insert(struct Node *H[],int key)
{
    int index=hash(key);
    SortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i,key=22;

    for(i=0;i<10;i++)
        HT[i]=NULL;

    insert(HT,12);
    insert(HT,22);
    insert(HT,42);

    temp=Search(HT[hash(key)],key);

    if(temp)
        printf("Key is found...");
    else
        printf("Key is not found...");

    return 0;
}
