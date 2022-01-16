// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int max=0;
    int curr=0;
    
    int helper(TreeNode* root){
        if(root==NULL){
            return curr;
        }
        curr++;
        curr=helper(root->left);
        if(curr>max){
            max=curr;
        }
        curr--;
        curr++;
        if(curr>max){
            max = curr;
        }
        curr=helper(root->right);
        curr--;
        
        return curr;
    }
        
    int maxDepth(TreeNode* root) {
        int gg = helper(root);
        return max;
    }
};
