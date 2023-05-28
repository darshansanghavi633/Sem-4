#include<stdio.h>
int a[100],n,i,j;

void swap(int *i,int *j){
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

int partition(int a[],int low,int high){
    int pivot=a[high];
    i=j=low;
    for ( i = low; i < high; i++)
    {
        if (a[i]<pivot)
        {
            swap(&a[i],&a[j]);
            j++;
        }
    }
    swap(&a[j],&a[high]);
    return j;
    
}

void quicksort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}



void main(){
        printf("enter the number of elements in array:\n");
    scanf("%d",&n);
    printf("the elements in the array are:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}