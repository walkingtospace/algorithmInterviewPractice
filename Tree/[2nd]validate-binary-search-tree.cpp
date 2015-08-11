/*
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Questions
Any duplicated value? -> no.
what's minimum? can I use INT_MIN?

Insights
at least, time complexity is O(n) since we need to visit every node. 
Recursive would be one of nice option.
INORDER : simply ascending order guarranteed. -> need to remember the previous call's value -> using static or parameter + function

left child < itself < parent -> visit left child and do again -> visit right child and do again -> ... -> if any one of recursive call is false -> return false -> at the end, return true.

Edgecases
[10,5,15,null,null,6,20] -> a right child 6 is smaller than its grandparent 10

{1}

unbalanced tree:
     2
    1
  -1 
-2

!!!!!!!!!!!!!!! very careful with using INT_MIN.
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
    long long min = LLONG_MIN;
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        if(!isValidBST(root->left) || min >= root->val) {
            return false;
        }
        
        min = root->val;
        
        if(!isValidBST(root->right) || min < root->val) {
            return false;
        }
        
        return true;
    }
};
