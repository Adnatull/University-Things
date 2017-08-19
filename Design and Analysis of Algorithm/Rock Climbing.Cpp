#include <stdio.h>

/*

input
5
1   2   3   4   5
6   5   9   10  11
99  12  3   55  1
323 55  6   3   3
12  323 656 99  74

*/


int dp[110][110];
int mat[110][110];
int n;

void findmin(int sum, int i, int j) {

    if(i<0 || j<0 || i>=n || j>=n) return;

    if(sum+mat[i][j]<dp[i][j]) {
        dp[i][j] = sum+mat[i][j];
        findmin(dp[i][j],i+1,j-1);
        findmin(dp[i][j],i+1,j);
        findmin(dp[i][j],i+1,j+1);
    }
    return;
}

int main() {

   // freopen ("in.txt", "r", stdin);

    scanf ("%d",&n);
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++) scanf ("%d",&mat[i][j]),dp[i][j]=100000;

    for (i=0; i<n; i++) findmin(0,0,i);

    int mi = 100000;
    for (i=0; i<n; i++) if(mi>dp[n-1][i]) mi = dp[n-1][i];

    printf ("%d\n", mi);

    return 0;
}
