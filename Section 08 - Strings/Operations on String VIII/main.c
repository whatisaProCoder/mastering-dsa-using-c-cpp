#include <stdio.h>
#include <stdlib.h>

///Checking if 2 Strings are Anagram (distinct letters, duplicates also valid)

int main() //only for lowercase alphabets
{
    char A[]="decimal";
    char B[]="medical"; //2 Strings are assumed : equal sized
    int i;
    int H[26]={0};

    for(i=0;A[i]!='\0';i++)
        H[A[i]-97]++;

    for(i=0;B[i]!='\0';i++)
    {
        H[B[i]-97]--;
        if(H[B[i]-97]<0)
        {
            printf("ITS NOT ANAGRAM");
            break;
        }
    }
    if(B[i]=='\0') //means for loop reached the B-string's end perfectly
        printf("ITS ANAGRAM");
    return 0;
}
