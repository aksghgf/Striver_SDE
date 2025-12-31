Problem Link: 

#include <bits/stdc++.h> 
class DisjointSet{
	vector<int> parent, size;
	public:
	DisjointSet(int n) {
		parent.resize(n);
		for (int i=0; i<n; i++) parent[i] = i;
		size.resize(n, 0);
	}

	int findPrnt(int node) {
		if (parent[node] == node) return node;
		return parent[node] = findPrnt(parent[node]);
	}

	void unionBySize(int u, int v) {
		int ulp_u = findPrnt(u);
		int ulp_v = findPrnt(v);

		if (ulp_u == ulp_v) return;
		if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
	}

};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<pair<int,pair<int,int>>>edges;
	for(auto it:graph){
		int u=it[0];
		int v=it[1];
		int wt=it[2];
		edges.push_back({wt,{u,v}});
	}
	sort(edges.begin(),edges.end());

	DisjointSet ds(n+1);
	int mstWt = 0;

	for (auto it: edges) {
		int wt=it.first;
		 int u=it.second.first;
		 int v=it.second.second;

		
		if (ds.findPrnt(u) != ds.findPrnt(v)) {
			ds.unionBySize(u, v);
			mstWt += wt;
		}

		
	}
	return mstWt;
}
