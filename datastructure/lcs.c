#include <stdio.h>
#include <string.h>
int i, j, m, n, LCS_table[20][20];
char S1[20], S2[20];

void lcs()
{
    n = strlen(S1);
    m = strlen(S2);
    for (int i = 0; i < n; i++)
    {
        LCS_table[i][0] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        LCS_table[0][i] = 0;
    }
    //loop barabar yaad rakhna
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i-1] == S2[i-1])
            {
                LCS_table[i][j] = (LCS_table[i - 1][j - 1] + 1);
            }
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
            {
                LCS_table[i][j] = LCS_table[i - 1][j];
            }
            else
            {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }
    }
    int index = LCS_table[n][m];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s", lcsAlgo);
}

void main()
{
    printf("enter the text: \n");
    scanf("%s", S1);
    printf("enter the pattern:\n");
    scanf("%s", S2);
    lcs();
}