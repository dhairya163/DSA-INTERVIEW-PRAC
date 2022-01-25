// https://leetcode.com/problems/invert-binary-tree/

// Given the root of a binary tree, invert the tree, and return its root.

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
    void inverttree(TreeNode* &root){
        if(root == NULL){
            return;
        }
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        inverttree(root->left);
        inverttree(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        inverttree(root);
        return root;
    }
};
