/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Question
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

O(n) solution

insights
1: To make profit, we should sell the stock when the price becomes 'higher'
2: We should keep 'min' -> but the the selling price next to min wouldn't guarrante the max gap..-> store min and gap at the same time.
3: So, compare gap with the current min.

edge cases 
1. what if all prices are ascending order?
2. what if all prices are descending order?
3. what if all prices are all flat? -> what should be the answer?

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int curMin = 9999999;
        int curGap = 0;
        
        for(int i=0; i < prices.size() ; ++i) {
            curMin = min(curMin, prices[i]);
            if(prices[i] - curMin > curGap) {
                curGap = prices[i] - curMin;
            } 
        }
        
        return curGap;
    }
};
