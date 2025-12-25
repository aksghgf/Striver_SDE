Problem Link: https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
#define ll long long 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	ll s1 = ((ll)n*(ll)(n+1))/2;
	ll s2 = ((ll)n*(ll)(n+1)*(ll)(2*n+1))/6;

	ll sum1 = 0, sum2 = 0;
	for (int i=0; i<n; i++){
		sum1+=(ll)arr[i];
		sum2+=(ll)arr[i]*(ll)arr[i];
	}

	ll diff = s1 - sum1;
	ll y = s2 - sum2;

	ll sum = y/diff;

	ll missing = (sum+diff)/2;
	ll repeating = sum-missing;
	return {missing, repeating};
	
}
