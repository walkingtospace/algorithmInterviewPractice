/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

Questions
Is the length given? -> yes

Insights
the key point is using MAX()
iterate from 0 to end, store current available max jump, and search max() within jump range -> update max and do again.
quit condition : if max == 0 

Edgecases


*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int maxJump = 0;
        while((i < nums.size()) || maxJump > 0) {
            maxJump = max(nums[i], maxJump);
            
            if((i+maxJump) >= nums.size()-1) {
                return true;
            } else if(maxJump > 0) {
                i++;
                maxJump--;
            } else {
                return false;
            }
        }
        
        return false;
    }
};
