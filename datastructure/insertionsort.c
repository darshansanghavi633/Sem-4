#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int n,i,j;
    printf("enter the number of elements in array:\n");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=rand();
    }
    int d=clock();
    for(j=1;j<n;j++){
        int key = a[j];
        i=j-1;
        while (i>=0 && key<a[i])
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
        
    }
    int b=clock();
    printf("average time complexity: %d",(b-d));
    
}