#include<stdio.h>
#include <stdlib.h>
#include<time.h>
void main()
{
int a[20000];
int i,j,t;
for(i=0;i<20000;i++)
{
a[i]=rand();
}
int imin;
int b=clock();
for(i=0;i<19999;i++)
{
imin=i;
for(j=i+1;j<20000;j++)
{
while(a[j]<a[imin])
{
imin=j;
}
}
t=a[imin];
a[imin]=a[i];
a[i]=t;
}
int c=clock();
printf("Average Case:%d\n",(c-b));
int d=clock();
for(i=0;i<19999;i++)
{
imin=i;
for(j=i+1;j<20000;j++)
{
while(a[j]<a[imin])
{
imin=j;
}
}
t=a[imin];
a[imin]=a[i];
a[i]=t;
}
int e=clock();
printf("Best Case:%d\n",(e-d));
int f=clock();
for(i=0;i<19999;i++)
{
imin=i;
for(j=19999;j>0;j--)
{
while(a[j]>a[imin])
{
imin=j;
}
}
t=a[imin];
a[imin]=a[i];
a[i]=t;
}
int g=clock();
printf("Worst Case:%d",(g-f));
}