/*
https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.


Some decent solution:

public int majorityElement(int[] nums) {
    Arrays.sort(nums);
    return nums[nums.length/2];
}

*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int,int> counter;
        int max = -9999, key = 0;
        
        for(int i=0; i< num.size() ; ++i) {
            counter[num[i]]++;
        }
        
        for(map<int,int>::iterator it=counter.begin(); it != counter.end() ; ++it) {
            if(max < it->second) {
                max = it->second;
                key = it->first;
            }   
        }
        
         return key;
    }
    
};
