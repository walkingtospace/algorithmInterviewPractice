/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


Questions
Is the order of generated output not matter? -> yes
what is the range of n?  n=0 ? n=1000?
what does that mean 'well-formed' exactly? => closed - opened parentheses pair

Insights
find a 'rule' to generate well-fored pair automatically

n=1 ()
n=2 () // (()) [insert], ()() [attach] 
n=3 (), (()), ()() // (()()) [insert 1-1], ((())) [insert 1-2] , (())() [insert 2-1 or attach], ()(())[insert2-2 or attach], ()()() [attach]
n=4 => from n=3, attach and insert. 
...

1. recursive solution would be nice since the creation rule seems to keep iterating.
2. using unordered_map<string, int> to avoid duplications 
3. in every call, n-- and iterate every stored pair, insert () and restore.
4. if n == 0, convert map into vector and return.

TS: O(n+n^2) -> O(n^2) since we should iterate every stored pair for every recursive call
SS: O(n)

Edgecases
n=0,
n=1

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        unordered_set<string> parenSet;
        
        createParen(n, parenSet);
        
        for(auto it = parenSet.begin(); it != parenSet.end() ; ++it) {
            res.push_back(*it);    
        }
        
        return res;
    }
    
    void createParen(int n, unordered_set<string>& parenSet) {
        unordered_set<string> tempSet;
        string minParen = "()";
        
        if(parenSet.empty()) {
            parenSet.insert(minParen);
            n--;
        }
        
        if(n == 0) return;
        
        for(auto it = parenSet.begin() ; it != parenSet.end() ; ++it) {
            string str = (*it);
                
            for(auto k = 0; k < str.length(); ++k) {
                tempSet.insert(str.substr(0,k) + minParen + str.substr(k));       
            }
        }
        
        parenSet.clear();
        parenSet = tempSet;
        
        createParen(--n, parenSet);
    }
};
