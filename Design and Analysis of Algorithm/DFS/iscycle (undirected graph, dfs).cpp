#include <bits/stdc++.h>

using namespace std;

vector <int> graph[123456];
bool mark[123456];
//DFS undirected graph
bool iscycle(int n, int parent) {

    mark[n] = true;
    int length = graph[n].size();
    for (int i=0; i<length; i++) {

        int v = graph[n][i];
        if(!mark[v]){
            if(iscycle(v,n)) return true;
        } else if(v!=parent) return true;
    }
    return false;
}

int main() {

   // freopen ("in.txt", "r", stdin);

    int n,e;
    cin >> n >> e;

    int x,y;
    for (int i=1; i<=e; i++) {

        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int source;
    cin >> source;
    int parent = INT_MAX;

    if(iscycle(source,parent)) cout << "The graph contains cycle.\n";
    else cout << "There is no cycle in this graph.\n";


    return 0;
}
