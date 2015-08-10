/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


A[i]가 0인 elemant가 있을때, 이를 jump할 수 있는지 여부만 없는지만 판별하면 간단.

greedy algorithm으로 매 step마다 range 내에서 현재위치 i+x[i]가 maximum이 되도록 무조건 가장 높은 값을 선택하면서 i++로 순회한다.
i != n-1인데 값이 0일때, 현재까지 저장된 maxjump값이 현재 A[i]를 skip할 정도로 크다면(maxJump > i) i=maxJump로 이를 뛰어넘고, 그렇지 못하다면 return false. i가 n까지 무사히 증가한 경우에는 0이 없거나 무사히 0인 부분을 뛰어넘은 것이므로 return true 

시간복잡도 : O(n)
공간복잡도 : O(1)
목표 : 1번에 accepted 받기
결과 : [2,0,2,0,1]에서 true를 리턴해야 하는데 wrong을 리턴함(이유: maxJump>i일때 i=maxjump가 아니라 maxJump-1해야함. 왜냐하면 곧바로 i++실행되어 A[maxJump]를 순회하지 않고 skip하므로). 2번만에 accepted
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        int maxJump = 0;
        
        for(int i=0; i<n; i++) {
            maxJump = max(A[i]+i, maxJump);
            
            if(i != n-1 && A[i] == 0) {
                if(maxJump > i) i = maxJump-1;
                else return false;
            }
        }   
        
        return true;
    }
};
