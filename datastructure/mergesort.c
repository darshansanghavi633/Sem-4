#include<stdio.h>
int a[100],b[100],n;

void merge(int a[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=high){
        b[k]=a[j];
        j++;
        k++;}
    }
    if(j>high){
        while(i<=mid){
        b[k]=a[i];
        i++;
        k++;}
    }
    //low ke jagah low and high ke jagah high
    for(int i=low;i<=high;i++){
        a[i]=b[i];
    }
    
    
}

void mergesort(int a[],int low,int high){
    int mid;
    if(low<(high-1)){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
    merge(a,low,mid,high);
    }
}



int main(){
    printf("enter the number of elements in array:\n");
    scanf("%d",&n);
    printf("the elements in the array are:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
        printf("sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}  