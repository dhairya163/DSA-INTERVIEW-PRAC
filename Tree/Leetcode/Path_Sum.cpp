// https://leetcode.com/problems/path-sum/

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
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
    bool flag = false;
    
    void helper(TreeNode* root , int target , int valuecur){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root ->right == NULL){
            valuecur = valuecur + root->val;
            if(target == valuecur){
                flag = true;
            }
            return;
        }
        
        helper(root->left,target,valuecur + root->val);
        helper(root->right,target,valuecur + root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0);
        return flag;
    }
};
