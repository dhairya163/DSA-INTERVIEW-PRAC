// https://leetcode.com/problems/symmetric-tree/

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    
    bool helper(TreeNode* first , TreeNode* second){
        if(first == NULL && second == NULL){
            return true;
        }
        if(first == NULL && second != NULL){
            return false;
        }
        if(first != NULL && second == NULL){
            return false;
        }
        if(first->val != second->val){
            return false;
        }
        if(first->val == second->val){
            return helper(first->left , second->right) && helper(first->right , second->left);
        }
        return helper(first->left , second->right) && helper(first->right , second->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};
