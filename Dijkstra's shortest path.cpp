Problem Link: https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_8230755?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int, int>> adj[vertices];
    for (auto it: vec) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(vertices, INT_MAX);
    pq.push({0, source});
    dis[source] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto nb : adj[node]) {
            int nbNode = nb.first;
            int nbDist = nb.second;

            if (dist + nbDist < dis[nbNode]) {
                dis[nbNode] = dist + nbDist;

                pq.push({dis[nbNode], nbNode});
            }
        }
    }

    return dis;
}
