#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(char str1[])
{  
    int length = strlen(str1);

    for(int i = 0;i < length ; i++){
        if(str1[i]!=str1[length -1 -i])
        return 0;
    }
    return 1;
}

void reverse1(char str1[]){
    int length = strlen(str1);
}

void reverse2(char str1[], char str2[]){
    int length = strlen(str1);
    for(int i = 0; i < length; i++){
        str2[i] = str1[length-i-1];
    }
    str1[length] = '\0';
}
int main()
{
    char str[20];
    char rev_str[20];
    char return_str[20];

    scanf("%s",str);
    scanf("%s", rev_str);
    if(isPalindrome(str)==1)
    printf("yes\n");
    else
    {
       printf("no\n");
    }
    reverse1(rev_str);
    reverse2(rev_str, return_str);

    printf("%s\n", rev_str);
   
 }
