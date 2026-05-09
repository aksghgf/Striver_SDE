Problem Link: https://www.codingninjas.com/studio/problems/check-bipartite-graph_8230761?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include "bits/stdc++.h"

bool bfs(int node, int col[], vector<int> adj[]) {
	col[node] = 0;

	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (auto it: adj[i]) {
			if (col[it] == -1) {
				col[it] = (!col[i]);
				q.push(it);
			}

			else if (col[i] == col[it]) return false;
		}
	}
	return true;
}


bool dfs(int node, int col[], vector<int> adj[], int color) {
	col[node] = color;

	for (auto nb: adj[node]) {
		if (col[nb] == -1) {
			if (dfs(nb, col, adj, !col[node]) == false) return false; 
		}
		else if (col[nb] == col[node]) return false;
	}

	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();

	vector<int> adj[n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (edges[i][j] == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int col[n];
	for (int i=0; i<n; i++) col[i] = -1;
	for (int i=0; i<n; i++) {
		if (col[i] == -1) {
			// if (bfs(i, col, adj) == false) return false; 
			if (dfs(i, col, adj, 0) == false) return false;
		}
	}
	return true;
}
