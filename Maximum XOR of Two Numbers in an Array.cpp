Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-xor-of-two-numbers-in-an-array_8230852?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
int maximumXor(vector<int> A) {
  int maxXr = 0, n = A.size();

  for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        int xr = A[i]^A[j];
        maxXr = max(xr, maxXr);
      }
  }

  return maxXr;
}
