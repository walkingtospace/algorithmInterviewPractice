/*
https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.


Questions
No overflow -> yes
the length is given? -> yes
all negative -> at least one number

Insights
store min separately
1. if negative -? ignore  -> can be included at 3.
2. else positive -> add up
3. else negative but sum is positive -> that's the key point. ->  keep the previous and add up.. and use max().
4. all negative or sum is negative ->  
start with small example : [2,-1,100]
Edgecases
all negative, or zero
all positive
all negative but one is positive or zero

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -99999999;
        int curMax = 0;
        int cntNegative = 0;
        
        for(int i=0; i< nums.size() ; ++i) {
            if(nums[i] < 0) cntNegative++;
            maxSum = max(nums[i], maxSum);
        }
        
        if(cntNegative == nums.size()) return maxSum;
        
        for(int i=0; i< nums.size() ; ++i) { // Need refactoring
            if(nums[i] > 0) {
                curMax += nums[i];
            } else if(nums[i] + curMax >= 0) {
                curMax += nums[i];
            } else if(nums[i] + curMax < 0){
                curMax = 0;
            }
            
            maxSum = max(maxSum, curMax);
        }
        
        return maxSum;
    }
};
