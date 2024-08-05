#include <stdio.h>
#include <stdlib.h>

///Validating a String

int valid(char *name)
{
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        if(!(name[i]>='A'&&name[i]<='Z')&&
           !(name[i]>='a'&&name[i]<='z')&&
           !(name[i]>='0'&&name[i]<='9'))
            return 0;
    }
    return 1;
}

int main()
{
    char *name="AniX?321";

    if(valid(name)==1)
        printf("Valid String.");
    else
        printf("Invalid String");

    return 0;
}
