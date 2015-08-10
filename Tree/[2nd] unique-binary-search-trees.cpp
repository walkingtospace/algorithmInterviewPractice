/*
https://leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Questions
n = 1
1

n = 2
  2
1

1
  2

n = 3
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
n = 4
1       2       1      1 
  4   1   4       4      2
 3      3       2          4
2                 3      3
...

    5
  1   7    
     6  8
          9
          
Insights
There should be a recursive 'rule' for tree problem.

!!!! very nice solution & explanation : https://leetcode.com/discuss/24282/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
f(m,n) = the number of BST that m is root and 1 ~ n elements (1 <= m <= n)
g(n) = the number of BST consisting of n elements
g(0)=1, g(1)=1. 
g(n) = f(1, n) + f(2, n) + ... + f(n, n). 
f(m,n) = g(m-1) * g(n-m) since m can be root and g(m-1) can be leftside of the BST, and the remaining g(n-m) can be the rightside.
So, by combining these two formulas : g(n) = g(0) * g(n-1) + g(1) * g(n-2) + … + g(n-1) * G(0).

Using DP : 

Edgecases
n = 0,1


*/

class Solution {
public:
    int numTrees(int n) {
        int G[n+1] = {0,};
        G[0] = 1;
        G[1] = 1;
        
        for(auto i = 2; i <= n ; ++i) {
            for(auto j = 1 ; j <= i ; ++j) {
                G[i] += G[j-1] * G[i-j];
            }
        }
        
        return G[n];
    }
};
