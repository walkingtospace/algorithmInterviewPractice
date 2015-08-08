/*
https://leetcode.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Questions
all positive -> no
unique? what if the given inputs are same? [0,0,0,1]-> unique.

Insights
1. simple solution : sort(O(nlogn)) and find kth largest number
2. using minheap : O(n) ~ O(nlogn)
3. using tournament algorithm : O(klogn + n). consturction cost: n/2 + n/4 + n/8 ... = O(1), searching cost : O(klogn) 

How to find kth?
when each iteration, compare adjacent elements, and move bigger one -> keep doing -> construct binary search -> find ith element takes logn since the tree is binary tree. Therefore finding kth element takes O(k log n + n)

[1,2,4,5,5,55,231,23,2] -> [2,5,55,231,2] -> [5,231] -> [231]
5,55,23

Edgecases
[1]
[1,2,3]
[0,0,0]

!!!!!!!!!!!!!!!! refered to https://leetcode.com/discuss/36966/solution-explained !!!!
Need to solve it again later.

*/

class Solution {
public:
   int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo < hi) {
            int j = partition(nums, lo, hi);
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        
        return nums[k];
    }

    int partition(vector<int>& a, int lo, int hi) {
        int i = lo;
        int j = hi + 1;
        
        while(1) {
            while(i < hi && less(a[++i], a[lo]));
            while(j > lo && less(a[lo], a[--j]));
            if(i >= j) {
                break;
            }
            
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
         
        int tmp = a[lo];
        a[lo] = a[j];
        a[j] = tmp;
        
        return j;
    }

    bool less(int v, int w) {
        return v < w;
    }
};
