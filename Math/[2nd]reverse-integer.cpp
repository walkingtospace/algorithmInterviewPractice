/*
https://leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

questions
Should I care about the overflow when reverse?
How to handle the case if the last digit is '0'? e.g., -100 => -1?

insights
1. reverse with mathmetical way -> need efficent digit shift
2. reverse with string conversion.

edge cases
-1000
10000000009 -> 9000000001 overflow
*/

class Solution {
public:
    int reverse(int x) {
        long long res = 0; //to avoid overflow. not a best option
        
        while(x) {
            int val = x % 10;
            
            x /= 10; //key point to reduce a lot of codes
            res = res * 10 + val; 
             
            if (res > numeric_limits<int>::max() || res <= numeric_limits<int>::min()) {
                return 0;
            }
        }
        
        return res;
    }
};
