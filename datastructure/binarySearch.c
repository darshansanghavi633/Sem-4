#include <stdio.h>
int BinarySearch(int a[], int high, int key)
{
    int low = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, key, result;
    printf("enter number of elements in array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter key that need to be searched:\n");
    scanf("%d", &key);
    result = BinarySearch(a, n, key);
    if (result == -1)
    {
        printf("key not found\n");
    }
    else
    {
        printf("Key is found at %dth index in the array\n", result);
    }
    return 0;
}