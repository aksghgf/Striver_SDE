Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_8230736?challengeSlug=striver-sde-challenge&leftPanelTab=0

int longestSubSeg(vector<int> &arr , int n, int k){
    // int cnt = 0;
    // int maxCnt = 0;

    // for (int i=0; i<n; i++){
    //     if (arr[i] == 1) cnt = 1;
    //     else cnt = 0;

    //     int j=i+1, updatelft = k;
    //     while (j<n){
    //         if (arr[j] == 0 && updatelft != 0) updatelft--;
    //         else if (arr[i] == 0 && updatelft == 0) break;
    //         cnt++; 
    //     }
    //     maxCnt = max(maxCnt, cnt);
    // }
    // return maxCnt;
    int i=0,j=0;

    for( i=0;i<n;i++){

        if(arr[i]==0){

            k--;

        }

        if(k<0 && arr[j++]==0){

            k++;

        }

    }

    return i-j;
}
