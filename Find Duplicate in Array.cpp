Problem Link: https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	map<int, int> fic;
	for (int i=0; i<n; i++){
		fic[arr[i]]++;
	}

	for (auto it: fic){
		if (it.second > 1) return it.first;
	}
	return -1;
}
