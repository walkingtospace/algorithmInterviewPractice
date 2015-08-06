/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Questions
1. all are positive integer? -> yes
2. the length is given? -> yes

Insights
sorted input -> binary search
find pivot => there is a rule: leftmost < med < rightmost. If the given input is rotated, it should have violated the rule. 
-> counter example? -> No. So, USING THIS RULE.
compare '3' times leftmost,rightmost,med.  
1. if target < med, target < leftmost -> go to right side
2. if target > med, target > med -> go to left side
counter example? -> the key point of this problem is finding counerexamples.

Edgecase
[1,2,3]
[1,2,0]
[1,2]
[2,1]

1 Failure case: [4,5,6,7,8,1,2,3], 8 => I couldn't consider the case line 61~64, line 52~55.
-> passed

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        int mid = 0;
        
        while(left <= right) {
            mid = (left+right)/2; //if the size is very big, it could be overflowed
            
            if(target == nums[mid]) {
                return mid;
            } else if(target < nums[mid] && target >= nums[left]) { //here
                right = mid - 1;
            } else if(target < nums[mid] && target < nums[left]) { //the other side
                if(nums[mid] < nums[left]) {
                   right = mid - 1;
               } else {
                   left = mid + 1;
               } 
            } else if(target > nums[mid] && target <= nums[right]) { //here
                left = mid + 1;
            } else if(target > nums[mid] && target > nums[right]) { //the other side
               if(nums[mid] < nums[right]) {
                   right = mid - 1;
               } else {
                   left = mid + 1;
               }
            } else {
                return -1;
            }
        }
        
        return -1;
    }
};
