/*
https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
  recursive call로 각 노드를 비교해야되는데 어떻게 비교해야할지가 관건
  left->left 와 right->right,
  left->right와 right->left를 매 recursive call 마다 비교해야하는 것을 알아차리는게 관건

  Time complexity: O(n)
 */

class Solution {
    public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        
        if(root->left && root->right) {
            return isSymmetric(root->left, root->right);
        } else if( root->left == NULL && root->right == NULL){
            return true;
        } else {
            return false;    
        }
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        else if(left == NULL || right == NULL) return false;
        else if(left->val != right->val) return false;
        
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
