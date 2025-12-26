Problem Link: https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   sort(arr.begin(), arr.end());

   // int i=0, j=arr.size()-1;
   
   // while (i<j){
   //    if (arr[i] + arr[j] == s){
   //       ans.push_back({arr[i], arr[j]});

   //       if (arr[i+1] == arr[i]) i++;
   //       else if (arr[j] == arr[j-1]) j--;
   //       else i++;
   //    }
   //    else if (arr[i] + arr[j] > s) j--;
   //    else i++;
   // }

   int n = arr.size();
   for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
         if (arr[i]+arr[j] == s) ans.push_back({arr[i], arr[j]});
      }
   }
   return ans;
}
