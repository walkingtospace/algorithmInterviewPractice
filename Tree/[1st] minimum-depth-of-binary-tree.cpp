/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
class Solution {
public:
    int minDepth(TreeNode *root) {
        return findMinimumDepth(root,1);
    }
    
    int findMinimumDepth(TreeNode* root, int depth) {
          if(root == NULL) return 0;
          int left = INT_MAX, right = INT_MAX;
          
          if(root->left != NULL) {
              left = findMinimumDepth(root->left, depth+1);
          } 
          
          if(root->right != NULL) {
              right = findMinimumDepth(root->right, depth+1);
          }
          
          if(root->left == NULL && root->right == NULL) return depth;
          
          return min(left, right);
   }
};
