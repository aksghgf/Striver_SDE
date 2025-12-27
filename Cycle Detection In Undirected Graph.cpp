Problem Link: https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_8230798?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include "bits/stdc++.h"

bool detectCycle(int i, vector<int> adjLs[], int vis[]) {
    vis[i] = 1;

    queue<pair<int, int>> q;
    q.push({i, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbour: adjLs[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if (parent != neighbour) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adjLs[n+1];
    for (int i=0; i<m; i++) {
        adjLs[edges[i][0]].push_back(edges[i][1]);
        adjLs[edges[i][1]].push_back(edges[i][0]);
    }

    int vis[n+1] = {0};
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adjLs, vis) == true) return "Yes";
        }
    }
    return "No";

}
