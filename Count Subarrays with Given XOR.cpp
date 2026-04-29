Problem Link: https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;

    for (int i=0; i<arr.size(); i++){
        xr = xr^arr[i];
        int rem = xr^k;

        cnt+=mpp[rem];
        mpp[xr]++;
    }

    return cnt;
}
