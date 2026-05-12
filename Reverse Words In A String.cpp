Problem Link: https://www.codingninjas.com/codestudio/problems/reverse-words-in-a-string_8230698?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <stack>
string reverseString(string &str){
	stack<string> st;

	
	for (int i=0; i<str.length(); i++) {
		string word = "";
		while (str[i] != ' ' && i<str.length()) {
			word+=str[i];
			i++;
		}
		
		if (!word.empty()) st.push(word);
	}	

	string ans = "";
	while (!st.empty()) {
		ans+=st.top();
		st.pop();
		ans.push_back(' ');
	}
	return ans;
}
