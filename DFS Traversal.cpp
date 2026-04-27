Problem Link: https://www.codingninjas.com/studio/problems/dfs-traversal_8230690?challengeSlug=striver-sde-challenge&leftPanelTab=0

void dfsFunc(int node, vector<int> adjLs[], vector<int>& dfs, vector<int>& vis) {
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it: adjLs[node]) {
        if (!vis[it]) {
            dfsFunc(it, adjLs, dfs, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> vis(V, 0);
    vector<int> adjLs[V];

    for (int i=0; i<E; i++) {
        adjLs[edges[i][0]].push_back(edges[i][1]);
        adjLs[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i=0; i<V; i++) {
        sort(adjLs[i].begin(), adjLs[i].end());
    }

    vector<vector<int>> dfs;
    // int cnt = 0;
    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            // cnt++;
            vector<int> component;
            dfsFunc(i, adjLs, component, vis);
            sort(component.begin(), component.end());
            dfs.push_back(component);
        }
    }
    // vector<int> v;
    // v.push_back(cnt);
    // auto it = dfs.begin();
    // dfs.insert(it, v);
    return dfs;

}
