/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

"well-formed" 의미를 시작전 명확하게 인터뷰어와 논의. 여기서는 열고( 닫는) 한쌍의 괄호쌍 의미
좀 더 정확하게 정의해보면, 닫힌 괄호가 나왔을때, 앞에 매칭되는 열린괄호가 최소한 1개는 존재해야함. 

n=1 (), 
n=2 (()), ()()
n=3 ()(()), (()()), ((())), (()()), (())(), ()()()
n=4 ..

직관적으로 n-1 에서 () 를 괄호 사이사이마다 넣어주면 n의 괄호 set이 완성된다. 
하지만 이때 괄호의 대칭성으로 인해 중복이 발생하므로 이를 제거하기 위해 hash_set(O(1))을 이용하여 자동으로 중복 검사 실시
Time complexity : O(1+2+11+...) = 정확한 계산 어려움
Space complexity : O(n일때의 괄호 set 갯수) 
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        unordered_set<string> parenSet;
        
        if(n == 0) {
            return res;    
        }
        
        string minParen = "()";
        
        res.push_back(minParen);
        
        for(int i=2; i<=n; ++i) {
        
            parenSet.clear();
            for(auto j=0; j<res.size(); ++j) {
                string str = res[j];
                
                for(auto k=0; k<str.length(); ++k) {
                    parenSet.insert(str.substr(0,k)+minParen + str.substr(k));       
                }
            }
            
            res.clear();
            
            for(auto it = parenSet.begin(); it != parenSet.end(); ++it) {
                res.push_back(*it);
            }
        }
        
        return res;
    }
};

