// https://leetcode.com/problems/binary-tree-tilt/

/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0 ;
    
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ls = helper(root->left);
        int rs = helper(root->right);
        
        sum = sum + abs(rs-ls);
        
        return ls+rs+root->val;
    }
    
    int findTilt(TreeNode* root) {
        int gg = helper(root);
        return sum;
    }
};
