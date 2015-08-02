/*
https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

questions
1. Is the given array is sorted?
2. Don't I have to worry about the overflow for two integer sum?
3. Are all elements positive?

insights
1. using hashtable: (target- element) will be hash key 

edge cases
what if target = 6, [3,2,5,6,3,3,4..] .. ? (the first element is half of the target value)
No exceptions unless there is the hash conflict
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> res;
        
        if(nums.size() == 0) return res;
        
        for(int i=0; i < nums.size() ; ++i) {
             table[nums[i]] = i;  
        }
        
        for(int j=0; j < nums.size() ; ++j) { //when lookup the table, the first index should find the other index first. 
             unordered_map<int, int>::iterator it = table.find(target - nums[j]);
             
             if(it != table.end() && it->second != j) {
                 res.push_back(j+1);
                 res.push_back((it->second) + 1);
                 
                 break;
             }
        }
        
    }
};
