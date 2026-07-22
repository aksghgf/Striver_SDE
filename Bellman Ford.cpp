Problem Link: https://www.codingninjas.com/studio/problems/bellman-ford_8230845?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1000000000);
    dist[src] = 0;
    for (int i=1; i<=n; i++) {
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1000000000 && dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest];
}
