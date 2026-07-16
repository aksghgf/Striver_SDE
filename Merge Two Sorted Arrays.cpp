 Problem Link: https://www.codingninjas.com/codestudio/problems/merge-two-sorted-arrays_8230835?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans(n+m);
	int k=0;
	int i=0, j=0;
	while (i<m && j<n){
		if (arr1[i] < arr2[j]) ans[k] = arr1[i++];
		else ans[k] = arr2[j++];
		k++;
	}

        while (i < m) {
          ans[k] = arr1[i++];
          k++;
        }
        while (j < n) {
          ans[k] = arr2[j++];
          k++;
        }


        return ans;
}
