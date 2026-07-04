Problem Link: https://www.codingninjas.com/studio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> res;
	priority_queue<pair<int, pair<int, int>>> pq;
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	pq.push({a[0]+b[0], {0, 0}});
	set<pair<int, int>> st;
	st.insert({0, 0});

	for (int i=0; i<k; i++) {
		int idx1 = pq.top().second.first;
		int idx2 = pq.top().second.second;
		pq.pop();
		res.push_back(a[idx1]+b[idx2]);
		if (idx1 + 1 < n && st.find({idx1 + 1, idx2}) == st.end()) {
			pq.push({a[idx1+1]+b[idx2], {idx1+1, idx2}});
			st.insert({idx1 + 1, idx2});
		}


		if (idx2 + 1 < n && st.find({idx1, idx2 + 1}) == st.end()) {
			pq.push({a[idx1]+b[idx2 + 1], {idx1, idx2 + 1}});
			st.insert({idx1, idx2 + 1});
		}
	}

	return res;
}
