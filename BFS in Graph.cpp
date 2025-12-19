Problem Link: https://www.codingninjas.com/studio/problems/bfs-in-graph_8230763?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

void bfsFunc(int node, vector<int> &vis, vector<int> adjLs[], vector<int>& bfs) {
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        bfs.push_back(vertex);
        for (auto it: adjLs[vertex]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adjLs[vertex];

    for (auto edge: edges) {
        adjLs[edge.first].push_back(edge.second);
        adjLs[edge.second].push_back(edge.first);
    }

    for (int i=0; i<vertex; i++) {
        sort(adjLs[i].begin(), adjLs[i].end());
    }

    vector<int> vis(vertex, 0);
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    for (int i=0; i<vertex; i++) {
        if (!vis[i]){
            bfsFunc(i, vis, adjLs, bfs);
        }
    }
    return bfs;
}
