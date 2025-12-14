Problem Link: https://www.codingninjas.com/codestudio/problems/modular-exponentiation_8230803?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1;
	long long new_x = x;

	while (n>0){
		if (n%2 != 0){
			ans = ((ans)%m*(new_x)%m)%m;
		}
		new_x = ((new_x)%m*(new_x)%m)%m;
		n = n>>1;
	}

	return (int)(ans%m);
}
