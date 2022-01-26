// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    int flag = 0;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> lol;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> gg;
        gg.push(root);
        gg.push(NULL);
        
        while(gg.size() != 0){
            TreeNode* temp = gg.front();
            gg.pop();
             
            if(temp == NULL){
                
                if(gg.size()!=0){
                gg.push(NULL);
                }
                if(flag == 0){
                    ans.push_back(lol);
                    lol.clear();
                    flag = 1;
                }
                else if(flag == 1){
                    reverse(lol.begin(), lol.end());
                    ans.push_back(lol);
                    lol.clear();
                    flag = 0;
                }
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
