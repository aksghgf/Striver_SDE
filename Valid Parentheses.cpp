Problem Link: https://www.codingninjas.com/codestudio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=0

bool isValidParenthesis(string expression)
{
    stack<char> st;

    for (int i=0; i<expression.size(); i++) {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[') st.push(expression[i]);

        else {
            if (st.empty()) return false;
          if (expression[i] == ']' && st.top() == '[')
            st.pop();
          else if (expression[i] == '}' && st.top() == '{' ) 
            st.pop();
        else if (expression[i] == ')' && st.top() == '(') 
            st.pop();
        else return false;
        }
    }
    if (!st.empty()) return false;
    return true;
}
