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
   
Questions
Is all element integer -> yes
the case that only root is there ? -> symmetric

Insights
how to compare/memorize 'position'? (comparing value is easy) -> 

1. BFS : using stack (mark some special char to memorize empty position), and counter for the number of children.
2. Recursive solution + stack : before passing root, use INORDER and store -> passing root -> pop element and compare in INORDER

Edgecases
{1}
{}
FAILED!!! : [1,2,3,3,null,2,null] -> we should check empty with.. -1?
      1
    2   3
   3   2      
  
  
  !! the below answer from some other guy's answer. very clear to understand.
  
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return helper(p->left,q->right) && helper(p->right, q->left); 
    }
};
