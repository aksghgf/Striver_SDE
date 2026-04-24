Problem Link: https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 

int merge(long long *arr, int l, int mid, int h) {
    int cnt = 0;
    int left = l;
    int right = mid+1;
    vector<long long> temp;

    while (left <= mid && right <= h) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            cnt+=(mid - left +1);
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);

    while (right <= h) temp.push_back(arr[right++]);

    for (int i=l; i<=h; i++) {
        arr[i] = temp[i-l];
    }
    return cnt;
}


int mergeSort(long long *arr, int l, int h) {
    if (l>=h) return 0;
    int mid = (l+h)/2;
    int cnt = 0;
    cnt+=mergeSort(arr, l, mid);
    cnt+=mergeSort(arr, mid+1, h);
    cnt+=merge(arr, l, mid, h);
    return cnt;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0, n-1);
}
