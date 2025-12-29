Problem Link: https://www.codingninjas.com/codestudio/problems/combination-sum-ii_8230820?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include "bits/stdc++.h"
void solver(int index, int sum, vector<int> &arr, vector<int> &temp
			/*set<vector<int>> &st*/, vector<vector<int>> &ans, int target) {
	

	if (index == arr.size()) {
		if (sum == target) ans.push_back(temp);
		return;
	}

	if (sum == target) {
		ans.push_back(temp);
		return;
	}
	for (int i=index; i<arr.size(); i++) {
		if (i>index && arr[i] == arr[i-1]) continue;
		if (arr[i] > target) break;

		temp.push_back(arr[i]);
		solver(i+1, sum+arr[i], arr, temp, ans, target);
		temp.pop_back();
	}
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
	// set<vector<int>> st;
	vector<vector<int>> ans;
	vector<int> temp;
	// solver(0, 0, arr, temp, st, target);
	solver(0, 0, arr, temp, ans, target);
	// for (auto it: st) {
	// 	ans.push_back(it);
	// }

	return ans;
}
