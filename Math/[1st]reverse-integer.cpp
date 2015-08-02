/*
https://leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
    public:
    int reverse(int x) {
        if(x < 10 && x > -10) return x;
        
        stringstream ss;
        ss << x;
        string res = ss.str();
        
        if(x < 0) std::reverse((++res.begin()),res.end()); 
        else std::reverse(res.begin(),res.end());
        
        return  atoi(res.c_str());
    }
};
