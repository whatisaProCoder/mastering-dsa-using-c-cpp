#include <stdio.h>
#include <stdlib.h>

///Counting Vowels and Consonants in a String

int main()
{
    char A[]="How are you?";
    int i,vcount=0,ccount=0,words=1;

    for(i=0;A[i]!='\0';i++) //counting vowels & consonants
    {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||
           A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U')
            vcount++;
        else if((A[i]>='A'&&A[i]<='Z')||(A[i]>='a'&&A[i]<='z'))
            ccount++;
        else if(A[i]==' '&&A[i-1]!=' ') //discarding white space
            words++;
    }

    printf("No. of vowels     = %d\n",vcount);
    printf("No. of consonants = %d\n",ccount);
    printf("No. of words      = %d",words);

    return 0;
}
