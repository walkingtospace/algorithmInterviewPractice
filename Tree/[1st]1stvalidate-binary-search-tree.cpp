/*
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

solution 1. 전체 노드를 순회하면서 tree를 streamlizing하여 extra 자료구조에 저장, 일일히 크기 비교(ex: {1,2,#,#,3} )
-> 가장 쉬운답, 인터뷰어가 원하는 답 아닌 것 같음

solution 2. 언제 invalid한가-> left branch: 자손의 값이 조상의 값보다 클때, right branch: 자손의 값이 조상의 값보다 작을때->
binarysearch tree의 특성을 생각해보자-> left로 갈수록 값이 '작아지고' right로 갈수록 값이 커짐 -> left, right branch를 recursive로 순회하면서 left의 경우 부모보다 갈수록 작아야하고, right는 부모보다 갈수록 커야함.

class Solution {
    public:
    int min;
    int max;
    
    bool isValidBST(TreeNode *root) {
        min = INT_MIN;
        max = INT_MAX;
        
        return isValidNode(root);
    }
    
    bool isValidNode(TreeNode* node) {
        bool left, right;
        int temp = max;
        
        if(node == NULL) return true;
        
        if(node->val >= max || node->val <= min ) return false;
        
        max = node->val;
        left = isValidNode(node->left);
        
        max = temp;
        min = node->val;
        right = isValidNode(node->right);
        
        return left && right;
    }
};

//inorder traversal 예제
class Solution {
    public:
    int min = INT_MIN;
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        
        if(isValidBST(root->left) == false) return false;
        
        if( root->val <= min) return false;
        
        min = root->val;
        
        if(isValidBST(root->right) == false) return false;
        
        return true;
    }
};*/

/*
해결의 열쇠는 inorder, right->left->parent traversal 둘다 단조증가ㅡ 또는 감소하므로 이를 눈치채는데에 있다.
ex:   5
    /  \
   2    6
  / \  / \
 1   4 3  8
 
 에서, inorder traversal의 경우 1->2->4->5->3->6->8 의 순으로 탐색하므로 root를 지나서도 언제나 단조증가함을 알수있다(따라서 3의 경우 wrong이므로 이 트리는 valid BST가 아님을 알 수 있다)
 따라서 하나의 전역변수에 이전 traversal의 값을 저장만 해두고 비교만 하는 방식으로 간단하게 해결할 수 있다.
*/

//right->left->parent traversal 예제
class Solution {
    
    public:
    int max = INT_MAX;
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
       
        if(isValidBST(root->right) == false) return false;
       
        if(root->val >= max) return false;
       
        max = root->val;
       
        if(isValidBST(root->left) == false) return false;
       
        return true;
    }
};
