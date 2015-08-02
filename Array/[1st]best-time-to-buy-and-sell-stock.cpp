/*
https://leetcode.com/submissions/detail/8250573/

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

testcase1 [3,6,1,3,2,11]
testcase2 [3,1,2,6,7,8,1,11]
testcase3 [7,6,5,4,3,4]

O(n^2) : brute-forth
O(n) :  1. traverse first->end, init max = 0
        2. compare profit, if(profit > max) max = profit
        3. if some element <= first, change first = that element's index
        4. start 2 again
        
        tip:
        if(a>b) a=b 는 항상 max, min 함수를 이용해서 elegant하게 줄일 수 있다
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        int sell = INT_MAX;
        
        for(int i=0 ; i<prices.size() ; i++) {
            sell = min(sell, prices[i]);    
            maxProfit = max(prices[i]-sell, maxProfit);
        }
        
        return maxProfit;
    }
};
