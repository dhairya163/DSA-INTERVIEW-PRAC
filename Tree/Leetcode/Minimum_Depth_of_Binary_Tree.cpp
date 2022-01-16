// https://leetcode.com/problems/minimum-depth-of-binary-tree/

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
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
    int min=999999999;
    
    void helper(TreeNode* root , int curr){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root ->right == NULL){
            if(min>curr){
                min = curr;
            }
            return;
        }
        helper(root->left,curr+1);
        helper(root->right,curr+1);
    }
        
    int minDepth(TreeNode* root) {
        helper(root,1);
        if(min==999999999){
            return 0;
        }
        return min;
    }
};
