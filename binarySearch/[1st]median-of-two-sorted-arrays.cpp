/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
         int temp[m+n];
         int leftIt = 0;
         int rightIt = 0;
         int cnt = 0;
         
         while(leftIt<m && rightIt<n) {
             if(A[leftIt] < B[rightIt]) {
                 temp[cnt++] = A[leftIt++];
             } else {
                 temp[cnt++] = B[rightIt++];
             }
         }
         
         while(leftIt<m) temp[cnt++] = A[leftIt++];
         while(rightIt<n) temp[cnt++] = B[rightIt++];
         
         if((m+n) % 2 == 1 ) {
             return temp[(m+n)/2];
         } else {
             return ((double)(temp[(m+n)/2] + temp[(m+n)/2-1])/2);
         }
    }
};
