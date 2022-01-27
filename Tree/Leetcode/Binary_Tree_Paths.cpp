// https://leetcode.com/problems/binary-tree-paths/

/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

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
    vector<string> ans;
    
    void helper(TreeNode* root , string result){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(result.size() == 0){
                result = result + to_string(root->val);
            }
            else{
                result = result + "->" + to_string(root->val);
            }
            ans.push_back(result);
            return;
        }
        if(result.size() == 0){
            helper(root->left , result + to_string(root->val));
            helper(root->right , result + to_string(root->val));
        }
        else{
            helper(root->left , result + "->" + to_string(root->val));
            helper(root->right , result + "->" + to_string(root->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root , "");
        return ans;
    }
};
