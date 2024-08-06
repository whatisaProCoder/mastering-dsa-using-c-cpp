#include <stdio.h>
#include <stdlib.h>

///Finding Length of a String

int main()
{
    char s[]="welcome";
    int i;

    for(i=0;s[i]!='\0';i++){}

    printf("Length is %d",i);

    return 0;
}
