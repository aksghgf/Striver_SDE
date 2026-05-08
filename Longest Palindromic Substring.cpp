Problem Link: https://www.codingninjas.com/studio/problems/day-12-longest-palindromic-substring_8230702?challengeSlug=striver-sde-challenge&leftPanelTab=0

string longestPalinSubstring(string s)
{
    int n =  s.length();
    int l,r;
    int start = 0, len = 1;

    for (int i=0; i<n; i++) {
        //even length
        l = i-1;
        r=i;

        while (l>=0 && r<n && s[l] == s[r]){
            if (r-l+1 > len) {
                start = l;
                len = r-l+1;
            }
            l--;
            r++;
        }

        //odd len 
        l = i-1;
        r = i+1;
        while (l>=0 && r<n && s[l] == s[r]) {
            if (r-l+1 > len) {
                start = l;
                len = r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(start, len);
}
