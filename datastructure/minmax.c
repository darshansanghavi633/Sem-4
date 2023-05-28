#include<stdio.h>
int min,max,a[100];
void minmax(int low,int high){
    int max1,min1,mid;
    if (low==high)
    {
        max=min=a[low];
    }
    else if (high==low-1)
    {
        if (a[low]>a[high])
        {
            max=a[low];
            min=a[high];
        }else{
            max=a[high];
            min=a[low];
        }
        
    }
    else{
        mid=(low+high)/2;
        minmax(low,mid);
        min1=min;
        max1=max;
        minmax(mid+1,high);
        if(max<max1){
            max=max1;
        }
        if(min>min1){
            min=min1;
        }
    }
    
    
}

void main(){
    int n;
    printf("enter number of elements:\n");
    scanf("%d",&n);
    printf("enter elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    minmax(0,n-1);
    printf("Minimum and Maximum values are %d and %d",min,max);
    
}