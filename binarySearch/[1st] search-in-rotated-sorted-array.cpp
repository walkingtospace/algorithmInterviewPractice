/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

    binary search를 응용하여 해결 가능.
    
    test case [4,5,6,7,8,1,2,3] , 8
              [7,8,1,2,3,4,5,6] , 8
        
    suedo code:    
    if pivot == target return pivot                     
    else if pivot < target
        if(high >= pivot) //right or left side 
            if(high < target) //left side
            else if(high >= target) //right side
        else if(high < pivot) //here
            
    else if pivot > target 
        if low >= pivot //left or right
            if(low > target) //left side
            else if(low <= target) right side 
        else if low < pivot //left 
        
    시간복잡도 : O(logn)
    결과 : equal 처리를 하지않아 1번째 시도 실패. 2번째 통과
*/


class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        int middle = 0;
        
        while(low <= high) {
            middle = (low + high)/2;
             
            if(A[middle] == target) {
                
                return middle;
            } else if(A[middle] < target) {
                if(A[high] >= A[middle]) { 
                    if(A[high] < target) { //left side
                        high = middle-1;
                    } else if(A[high] >= target) { //right side
                        low = middle+1;
                    }
                } else if(A[high] < A[middle]) { //this range has cut part
                        low = middle+1;                    
                }
            } else if(A[middle] > target) {
                 if(A[low] > A[middle]) { //this range has cut part
                        high = middle-1;
                } else if(A[low] <= A[middle]) { 
                    if(A[low] > target) { //right side
                        low = middle+1;
                    } else if(A[low] <= target) { //right side
                        high = middle-1;
                    }                                       
                }
            }
        }
        
        return -1;
    }
};
