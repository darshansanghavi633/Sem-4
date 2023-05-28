#include <stdio.h>
//ye bhul jata hu
#define TRUE 1
#define FALSE 0
int inc[50], w[50], sum, n;

//ye bhi
int promising(int i, int wt, int total)
{
    return (((wt + total) >= sum) && ((wt == sum) || (wt + w[i + 1] <= sum)));
}

void sumset(int i, int wt, int total)
{
    if (promising(i, wt, total))
    {
        if (wt == sum)
        {
            printf("{\t");
            for (int j = 0; j <= i; j++)
            {
                if (inc[j])
                    printf("%d\t", w[j]);
            }
            printf("}\n");
        }
        else
        {
            inc[i + 1] = TRUE;
            sumset(i + 1, wt + w[i + 1], total - w[i + 1]);
            inc[i + 1] = FALSE;
            sumset(i + 1, wt, total - w[i + 1]);
        }
    }
}

void main()
{
    int i, j, total = 0, n, temp;
    printf("Enter the number of elements in subset:\n");
    scanf("%d", &n);
    printf("Enter each value of the set:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("Input the sum value to create subset:\n");
    scanf("%d", &sum);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (w[j] > w[j + 1])
            {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
    printf("the given numbers in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", w[i]);
    }
    printf("\ntotal %d\n", total);
    //aur ye condition bhi
    if (total < sum)
    {
        printf("Subset is not possible\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            inc[i] = 0;
        }
        printf("the subset are:\n");
        sumset(-1, 0, total);
    }
}