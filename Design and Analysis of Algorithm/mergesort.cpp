#include <iostream>
#include <cstdio>

using namespace std;

int a[1000];

void merge(int left, int mid, int right) {

    int n1 = mid-left+1;
    int n2 = right - mid;
    int l[n1], r[n2];

    for (int k=left, i=0;i<n1; i++) l[i] = a[k++];
    for (int k=mid+1, i=0; i<n2; i++ ) r[i] = a[k++];

    int i,j,k;
    i=0, j=0, k = left;
    while (i<n1 && j <n2) {
        if(l[i]<r[j])
            a[k++]=l[i++];
        else a[k++] = r[j++];
    }

    while (i<n1) a[k++] = l[i++];

    while (j<n2) a[k++] = r[j++];
}

void merge_sort(int left, int right) {

    if(left<right) {

        int mid = (left+right)/2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);

    }

}

int main() {

  //  freopen ("min.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    merge_sort(0,n-1);

    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
