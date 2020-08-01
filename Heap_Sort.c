#include <stdio.h>
#include <stdlib.h>
void disp(int x[],int n);
void heapsort(int x[],int n);
int main()
{
    int a[] = {15,15,15,15,15,15,15,15};
    int n = 8;
    disp(a,n);
    heapsort(a,n);
    disp(a,n);
    return 0;
}
void  disp(int x[],int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}
void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void heapify(int x[],int n,int root)
{
    int i = root;
    int j = 2*i+1;
    int is_heap = 0;
    while(j < n && !is_heap)
    {
        if(j+1 < n && x[j+1] > x[j])
        {
            ++j;
        }
        if(x[j] > x[i])
        {
            swap(&x[j],&x[i]);
            i = j;
            j = 2*i + 1;
        }
        else
        {
            is_heap = 1;
        }
    }
}
void heapsort(int x[],int n)
{
    for(int i = n/2 -1;i >= 0;i--)
    {
        heapify(x,n,i);
    }
    for(int i = n-1;i >= 0;i--)
    {
        swap(&x[i],&x[0]);
        heapify(x,i-1,0);
    }
}