// https://leetcode.com/problems/binary-tree-maximum-path-sum/


/* 
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    int helper(TreeNode* root , int &maxi){
        if(root==NULL){
            return 0;
        }
        int leftsum = helper(root->left,maxi);
        int rightsum = helper(root->right,maxi); 
        if(leftsum < 0){
            leftsum = 0;
        }
        if(rightsum < 0){
            rightsum = 0;
        }
        maxi = max(maxi , leftsum + rightsum + root->val);
        return root->val + max(leftsum , rightsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};
