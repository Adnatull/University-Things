#include <bits/stdc++.h>

#define inf 10000000


/*
input
6 7
0 1 2
0 4 3
4 3 5
1 3 3
3 5 2
3 2 11
2 1 1
*/

using namespace std;


int main() {

   // freopen ("in.txt", "r", stdin);

    int n,e;
    scanf ("%d %d", &n, &e);



    int mat[n][n];

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) mat[i][j] = inf;


    int x,y,w;
    for (int i=0; i<e; i++) {
        scanf ("%d %d %d",&x, &y, &w);
        mat[x][y] = w;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if(mat[i][k]+mat[k][j]<mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf ("Distance from %d to %d is %d.\n",i,j,mat[i][j]);
        }
    }



    return 0;
}


