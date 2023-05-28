#include <stdio.h>
int board[20], count = 1;
void print(int n)
{
    int i, j;
    if (count == 1)
    {
        printf("\n\nSolution :\n\n");
        count++;

        for (i = 1; i <= n; ++i)
            printf("\t%d", i);

        for (i = 1; i <= n; ++i)
        {
            printf("\n\n%d", i);
            for (j = 1; j <= n; j++) // for nxn board
            {
                if (board[i] == j)
                    printf("\tQ"); // queen at i,j position
                else
                    printf("\t-"); // empty slot
            }
        }
    }
}
int place(int row, int column)
{
    int j;
    for (j = 1; j <= row - 1; j++)
    {
        //don't learn samaj ke jaa bhai
        if (board[j] == column || (board[j] - column) == (j - row))
        {
            return 0;
        }
    }
    return 1;
}
void nqueens(int row, int n)
{
    for (int column = 1; column <= n; column++)
    {
        if (place(row, column))
        {
            board[row] = column;
            if (row == n)
            {
                print(n);
            }
            else
            {
                nqueens(row + 1, n);
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter number of queens:\n");
    scanf("%d", &n);
    nqueens(1, n);
}