Problem Link: https://www.codingninjas.com/studio/problems/floyd-warshall_8230846?challengeSlug=striver-sde-challenge&leftPanelTab=1

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for (int i=0; i<=n; i++) dist[i][i] = 0;

    for (auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        dist[u][v] = wt;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if (dist[j][i] != 1e9 && dist[i][k] != 1e9) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
    return dist[src][dest];
}
