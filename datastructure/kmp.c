#include<stdio.h>
#include <string.h>
    void compute_failure_function(char *pattern, int *failure)
{
    int i = 1, j = 0, m = strlen(pattern);
    failure[0] = 0;
    while (i < m)
    {
        if (pattern[i] == pattern[j])
        {
            failure[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = failure[j - 1];
        }
        else
        {
            failure[i] = 0;
            i++;
        }
    }
}
int knuth_morris_pratt(char *text, char *pattern)
{
    int i = 0, j = 0, n = strlen(text), m = strlen(pattern);
    int failure[m];
    compute_failure_function(pattern, failure);
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            if (j == m - 1)
                return i - j;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = failure[j - 1];
        }
        else
        {
            i++;
        }
    }
    return -1;
}
int main()
{
    char text[100], pattern[100];
    printf("Knuth-Morris-Pratt String Matcher\nEnter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    int pos = knuth_morris_pratt(text, pattern);
    if (pos == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", pos);
    return 0;
}