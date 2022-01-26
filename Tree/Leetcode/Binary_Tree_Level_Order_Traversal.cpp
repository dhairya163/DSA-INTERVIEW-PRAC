// https://leetcode.com/problems/binary-tree-level-order-traversal/

/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        vector<int> lol;
        
        queue<TreeNode*> gg;
        gg.push(root);
        gg.push(NULL);
        
        while(gg.size() != 0){
            TreeNode* temp = gg.front();
            gg.pop();
            
            if(temp == NULL){
                if(gg.size() != 0){
                    gg.push(temp);
                }
                
                ans.push_back(lol);
                lol.clear();
                
            }
            
            else{
                lol.push_back(temp->val);
                if(temp->left != NULL){
                    gg.push(temp->left);
                }
                if(temp->right != NULL){
                    gg.push(temp->right);
                }
            }
        }
        
        return ans;
    }
};
