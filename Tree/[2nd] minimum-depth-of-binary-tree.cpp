/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


Questions
[0] is 1? ->yes

Insights
REMIND ' nearest leaf', not just root node like this case [1,2] should be 2 since 1-2 is the shortest path.
DEFINITION OF LEAF : A NODE HAVING NO CHILD.
BST -> the easiest way to find min depth. -> check every next generation is even or odd (odd means min depth)
recursive solution -> shoudld a parameter to store min or use global variable.

Edgecases
{}
{0}
unbalanced tree

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int minDepth = 1;
        
        if(root == NULL) {
            return 0;
        } else if((root->left == NULL) && (root->right == NULL)) {
            return 1;
        }
        
        queue.push(root);
        
        while(!queue.empty()) {
            int size = queue.size();
            
            for(int i=0 ; i < size ; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if(node->left == NULL && node->right == NULL) {
                    return minDepth;
                } else if(node->left != NULL && node->right == NULL) {
                    queue.push(node->left);
                } else if(node->right != NULL && node->left == NULL) {
                    queue.push(node->right);
                } else {
                    queue.push(node->left);
                    queue.push(node->right);
                }
            }
            
            minDepth++;
        }   
        
        return minDepth;
    }
};
