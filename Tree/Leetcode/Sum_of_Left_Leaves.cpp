// https://leetcode.com/problems/sum-of-left-leaves/

/*
Given the root of a binary tree, return the sum of all left leaves.
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
    int sum = 0;
    
    void helper(TreeNode* root , int fromleft){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(fromleft == 1){
                sum = sum + root->val;
                return;
            }
            else{
                return;
            }
        }
        helper(root->left , 1);
        helper(root->right,0);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root,0);
        return sum;
    }
};
