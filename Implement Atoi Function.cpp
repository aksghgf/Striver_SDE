Problem Link: https://www.codingninjas.com/studio/problems/implement-atoi-function_8230776?challengeSlug=striver-sde-challenge&leftPanelTab=0


#include <bits/stdc++.h> 
int atoi(string str) {
    bool pos = true;

    string ans = "";

    for (int i=0; i<str.length(); i++) {
        if (str[i]>='0' && str[i]<='9') ans+=str[i];
        else if (str[i] == '-') pos = false;
    }

    int res = stoi(ans);

    return pos==true? res:-res;
}
