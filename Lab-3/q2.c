#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *inp, char *pattern)
{
    int inpLen = strlen(inp);
    int patternLen = strlen(pattern);
    int i = 0;
    while (i <= inpLen - patternLen)
    {
        int j = 0;
        while (j <= patternLen && inp[i + j] == pattern[j])
        {
            j++;
            if (j == patternLen)
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}
int main()
{
    char inp[100];
    char pattern[100];
    printf("Enter the string : ");
    gets(inp);
    printf("Enter pattern : ");
    gets(pattern);

    printf("Pattern found at : %d\n", find(inp, pattern));
    return 0;
}