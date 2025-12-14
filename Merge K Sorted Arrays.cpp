Problem Link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_8230770?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;

    for (int i=0; i<kArrays.size(); i++) {
        pq.push({kArrays[i][0], {i, 0}});
    }


    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int ele = it.first;
        int li = it.second.first;
        int di = it.second.second;

        ans.push_back(ele);

        di++;
        if (di < kArrays[li].size()) {
            pq.push({kArrays[li][di], {li, di}});
        }
    }

    return ans;
}
