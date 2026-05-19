Problem Link: https://www.codingninjas.com/studio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int> freq(26, 0);

    for (int i=0; i<str1.size(); i++) {
        freq[str1[i]-'a']++;
    }

    for (int i=0; i<str2.size(); i++) freq[str2[i] - 'a']--;

    for (int i=0; i<26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}
