#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[largest]<a[left])
        largest = left;
    if(right<n && a[largest]<a[right])
        largest = right;
    if(largest!=i) {
        int temp = a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
    return;
}

void sort( int a[], int n) {
    int l = n/2-1;
    int i;
    for (i=l; i>=0; i--)
        heapify(a,n,i);
    int temp;
    for (i=n-1; i>=0; i--){
        temp = a[i];
        a[i]=a[0];
        a[0]=temp;
        heapify(a,i,0);
    }
}

int main() {
    int a[]={15,9,10,7,17,16};
    int n;
    n =sizeof(a)/sizeof(a[0]);
    sort(a,n);
    int i;
    for (i=0; i<n; i++)
        printf ("%d ",a[i]);
    return 0;
}
