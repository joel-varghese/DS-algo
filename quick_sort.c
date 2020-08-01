#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void display(int arr[],int size)
{
    int i;
    for(i=0;i < size;i++)
        printf("%d ",arr[i]);
}
int partition(int arr[],int l,int r)
{
    int p = arr[l];
    int i = l;
    int j = r+1;
    do
    {
        do
        {
            i = i+1;
        }
        while(i <= r && arr[i] < p);
        do
        {
            j = j - 1;
        }
        while(j >= l && arr[j] > p);
        swap(&arr[i],&arr[j]);
    }
    while(i<j);
    swap(&arr[i],&arr[j]);
    swap(&arr[l],&arr[j]);
    return j;
}
void quick(int arr[],int l,int r)
{
    if(l < r)
    {
        int s = partition(arr,l,r);
        quick(arr,l,s-1);
        quick(arr,s+1,r);
    }
}
int main()
{
    int arr[] = {10,80,30,90,40,50,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,n-1);
    printf("sorted array : \n");;
    display(arr,n);
    return 0;
}
