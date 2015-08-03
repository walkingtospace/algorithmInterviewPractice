/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

O(nk), k is the length of longest common prefix
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs[0].length() == 0) {
            
            return "";
        }
        
        string res = strs[0];
        
        for(int i=1; i<strs.size(); ++i) {
            int cnt = 0;
            string temp = "";
            
            while(res.length() > cnt && strs[i].length() > cnt && res.at(cnt) == strs[i].at(cnt)) {
                temp += res.at(cnt++);    
            }
            
            res = temp;
        }
        
        return res;
    }
};
