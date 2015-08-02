/*
https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

questions to ask before coding
1. nagative? postive?
2. no duplication?
3. don't consider over/underflow?
4. the answer always exists?

TC: O(n)
SP: O(n)

I did wrong at:
[3,4,5,6] 6 => I should have checked referring the same indices
[0,2,3,0] 0 -> (4,1) I should have considerted the order of indices
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> table;
        vector<int> res;
        
        for(int i=0; i<nums.size(); ++i) {
            table.insert(pair<int,int>(nums[i], i));
        }
        
        for(int i=0; i< nums.size(); ++i) {
             if(table.find(target - nums[i]) != table.end() && table[target - nums[i]] != i) { //except itselfs (3,3 to 6)
                if((i+1) < (table[target - nums[i]]+1)) {
                     res.push_back(i+1);
                     res.push_back(table[target - nums[i]]+1);
                } else {
                     res.push_back(table[target - nums[i]]+1);
                     res.push_back(i+1);
                }
                
                break;
             }
        }
        
        return res;
    }
};
