#include <stdio.h>
#include <stdlib.h>

///Comparing Strings and Checking Palindrome

void comparingStrings()
{
    char A[]="Painter";
    char B[]="Painting";
    int i,j;

    for(i=0,j=0;A[i]!='\0'&&B[i]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
            break;
    }

    if(A[i]==B[j])
        printf("Equal");
    else if(A[i]<B[j])
        printf("[%s] comes before [%s]",A,B);
    else
        printf("[%s] comes before [%s]",B,A);
}

void checkingPalindrome()
{
    char A[]="MADAM";
    int i,j;
    for(j=0;A[j]!='\0';j++){}
    j--;
    for(i=0;i<j;i++,j--)
    {
        if(A[i]!=A[j])
        {
            printf("%s is not palindrome.",A);
            return;
        }
    }
    printf("%s is palindrome.",A);
}

int main()
{
    comparingStrings();
    printf("\n");
    checkingPalindrome();

    return 0;
}
