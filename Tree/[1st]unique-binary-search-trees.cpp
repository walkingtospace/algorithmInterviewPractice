/*
https://leetcode.com/submissions/detail/10198848/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
BST의 정의 : 부모가 있고, 왼쪽 자식은 부모보다 작고, 오른쪽 자식은 부모보다 항상 큰 tree
접근 : 규칙이 일단 잘 안보이니 n = 1, 2, 3, 4까지 세어보면서 점화식이 나오나 살펴보기
n=1    1
n=2   1+1 = 2
n=3   2+1+2 = 5
n=4  5+2*1+1*2+5 = 14
n=5  14+5+(2*2)+5+14 = 42
n=6  42 + 14 + (2*5) + (5*2) + 14 + 42 = 132
n=7  132 + 42 + 14 + 10*10 + 14 + 42 + 132 = 

                    n=3, 2f(n-1) + f(n-2)*f(n-2)
                    n=4, 2f(n-1) + f(n-2)*f(n-2) 
f(n)  :             n=5, 2(f(n-1) + f(n-2)) + f(n-3)*f(n-3)
                    n=6, 2(f(n-1) +f(n-2)) + 2(f(n-3)*f(n-2)) 
                    n=7, 2(f(n-1) + f(n-2) + f(n-3)) + f(n-4)*f(n-4)
                     ...


*/

/* 다른사람의 답인데, 위의 점화식에서 대체 어떻게 아래 공식을 추출했는지 도저히..알수가 없다; */
class Solution {
public:
     int numTrees(int n) {
        long long ans = 1;
        for(int i = 1; i <= n; ++ i)
            ans  = ans * 2 * (2 * i - 1) / (i + 1);
        return (int) ans;
    }
};
