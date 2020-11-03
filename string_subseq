#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isSubsequence(char s[], char t[]) {
    int dp[1001];
    int ls = strlen(s);
    int ts = strlen(t);
    int prev, tmp;
    int i, j;

    for (i = 0; i <= ts; i++)
        dp[i] = 0;
    for (i = 0; i < ls; i++)
    {
        for (j = 0; j <= ts; j++)
        {
            if (j == 0)
            {
                prev = 0;
                continue;
            }
            if (s[i] == t[j - 1])
            {
                tmp = prev;
                prev = dp[j];
                dp[j] = tmp + 1;
            }
            else
            {
                prev = dp[j];
                if (dp[j] < dp[j - 1])
                    dp[j] = dp[j - 1];
            }
            //printf("%d ", dp[j]);
        }
        //printf("\n");

    }

    if (dp[ts] != 0)
        return 1;
    else return 0;
}
int main(){
    char s[20];
    char t[20];
    
    scanf("%s %s", s,t);

    if(isSubsequence(s,t) == 1)
        printf("yes\n");
    else 
        printf("no\n");
    }
