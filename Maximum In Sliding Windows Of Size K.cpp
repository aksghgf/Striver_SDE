Problem Link: https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<nums.size();i++)
    {
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        while(!dq.empty() && nums[dq.back()]<=nums[i])
        dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
