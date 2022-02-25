// https://leetcode.com/problems/delete-node-in-a-bst/

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.
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
    TreeNode* search(TreeNode* &root , int key){
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == key){
            return root;
        }
        
        if(root->val > key){
            if(root->left!= NULL && root->left->val==key){
                return root;
            }
            else{
                return search(root->left , key);
            }
        }
        else{
            if(root->right!= NULL && root->right->val==key){
                return root;
            }
            else{
                return search(root->right,key);
            }
        }
        return NULL;
    }
    
    TreeNode* findlastright(TreeNode* &root){
        if(root==NULL){
            return NULL;
        }
        if(root->right == NULL){
            return root;
        }
        else{
            return findlastright(root->right);
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* searched = search(root,key);
        
        if(searched == NULL){
            return root;
        }
        
        if(searched->val == key){
            if(searched->left == NULL){
                return searched->right;
            }
            else if(searched->right == NULL){
                return searched->left;
            }
            else{
                TreeNode* lastright = findlastright(searched->left);
                lastright->right = searched->right;
                return searched->left;
            }
        }
        
        if(searched->left!= NULL && searched->left->val == key){
            TreeNode* lastright = findlastright(searched->left->left);
            if(lastright == NULL){
                searched->left = searched->left->right;
                return root;
            }
            else{
                lastright->right = searched->left->right;
                searched->left = searched->left->left;
                return root;
            }
        }
        
        if(searched->right->val == key){
            TreeNode* lastright = findlastright(searched->right->left);
            if(lastright == NULL){
                searched->right = searched->right->right;
                return root;
            }
            else{
                lastright->right = searched->right->right;
                searched->right = searched->right->left;
                return root;
            }
        }
        
        
        return root;
    }
};
