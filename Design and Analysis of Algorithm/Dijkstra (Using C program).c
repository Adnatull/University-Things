#include <stdio.h>
#define N 5
#define mx 1000000

int graph[N][N];
int d[N], prev[N];
int visited[N];

void input_graph() {

    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) scanf ("%d", &graph[i][j]);
    }

}

void output_graph() {

    int u;
    for (u=0; u<N; u++) printf (" Node %d : Shortest distance %d\n",u, d[u]);

}

int extract_min() {

    int min_value = mx;
    int min = -1;
    int u;
    for (u=0; u<N; u++) {
        if(d[u]<=min_value && visited[u]==0) {
            min_value = d[u];
            min = u;

        }

    }
    return min;
}



void dijkstra() {
    int i=0, j=0;
    for (;i<N; i++) d[i]= mx, visited[i] = 0;

    int source = 0;

    d[source] = 0;


    int u = extract_min();

    while (u!=-1) {

        visited[u] = 1;
        for (i=0; i<N; i++) {
            if(graph[u][i]!=0) {
                int v = i;
                if(d[v]>d[u]+graph[u][v]) {
                    d[v] = d[u]+graph[u][v];
                     }

            }

        }
        u = extract_min();
    }

}


int main() {

   // freopen ("in.txt", "r", stdin);

    input_graph();
    dijkstra();
    output_graph();

    return 0;

}
