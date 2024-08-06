#include <stdio.h>
#include <stdlib.h>

///Changing Case of a String

void toLowerCase()
{
    char A[]="WELCOME";
    int i;

    for(i=0;A[i]!='\0';i++)
    {
        A[i]+=32; //A[i]-=32 for toUpperCase;
    }

    printf("%s\n",A);
}

void toggleCases()
{
    char A[]="w5lCOme";
    int i;

    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]>='A' && A[i]<='Z')
            A[i]+=32;
        else if(A[i]>='a' && A[i]<='z')
            A[i]-=32;
    }

    printf("%s\n",A);
}

int main()
{
    toLowerCase();
    toggleCases();

    return 0;
}
