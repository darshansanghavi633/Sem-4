#include <stdio.h>

int n_pages, n_frames, pages[30], frames[30], hit_count = 0, fault_count = 0, j = 0, i, k;
char check;
float hit_ratio, fault_ratio;

void main()
{
    printf("\nEnter the number of pages : ");
    scanf("%d", &n_pages);
    printf("\nEnter the number of frames : ");
    scanf("%d", &n_frames);
    printf("\nEnter the pages : ");
    for (i = 0; i < n_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < n_frames; i++)
    {
        frames[i] = -1;
    }
    for (i = 0; i < n_pages; i++)
    {
        check = 'F';
        for (k = 0; k < n_frames; k++)
        {
            if (pages[i] == frames[k])
            {
                check = 'H';
                hit_count++;
            }
        }
        if (j < n_frames && check != 'H')
        {
            frames[j] = pages[i];
            j++;
            fault_count++;
        }
        else if (j >= n_frames && check != 'H')
        {
            j = 0;
            frames[j] = pages[i];
            j++;
            fault_count++;
        }
        printf("%d\t\t\t", pages[i]);
        for (k = 0; k < n_frames; k++)
        {
            if (frames[k] != -1)
            {
                printf("%d\t ", frames[k]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("%c\n", check);
    }
}