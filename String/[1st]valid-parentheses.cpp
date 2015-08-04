/*
https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

TC: O(n)
SC: O(n)

By using map<char,char>, we can save much code lines.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length() ; ++i) {
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                
                st.push(s[i]);
            } else {
                if(st.empty() == false) {
                    char openStr = st.top();
                    
                    st.pop();
                    
                    if(s[i] == ')' && openStr == '(') {
                        
                        continue;
                    } else if(s[i] == ']' && openStr == '[') {
                        
                        continue;
                    } else if(s[i] == '}' && openStr == '{') {
                        
                        continue;
                    } else {
                        
                        return false;   
                    }
                } else {
                    
                    return false;
                }
            }
        }
        
        if(st.empty()) {
            
            return true;
        } else {
            
            return false;
        }
    }
};
