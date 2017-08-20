#include <bits/stdc++.h>

#define inf 10000000


/*
input
6 7
0
0 1 2
0 4 3
4 3 5
1 3 -2
3 5 2
3 2 11
2 1 1
*/

using namespace std;

struct node {
    int source, destination, cost;
};

int main() {

   // freopen ("in.txt", "r", stdin);


    int n,e;
    scanf ("%d %d", &n, &e);

    node graph[e];

    int source;
    scanf ("%d", &source);

    int x,y,w;
    for (int i=0; i<e; i++) {
        scanf ("%d %d %d",&x, &y, &w);
        graph[i].source = x;
        graph[i].destination= y;
        graph[i].cost = w;
    }

    int dist[n];
    for (int i=0; i<n; i++) dist[i] = inf;

    dist[source] = 0;

    for (int i=0; i<n; i++) {

        for (int j=0; j<e; j++) {
            x = graph[j].source;
            y = graph[j].destination;
            w = graph[j].cost;
            if(dist[y]>dist[x]+w)
                dist[y] = dist[x]+w;
        }
    }

    bool negetivefound = true;
    for (int i=0; i<e; i++) {
        int u = graph[i].source;
        int v = graph[i].destination;
        int z = graph[i].cost;

        if(dist[v]>dist[u]+z) {
            negetivefound = false;
            break;
        }
    }

    if(!negetivefound) {
        printf ("There exists negative cycles.\n");
    }
    else printf ("There is no negative cycles.\n");


    for (int i=0; i<n; i++) {
        printf ("%d \t \t Distance from source: %d\n",i,dist[i]);
    }



    return 0;
}

