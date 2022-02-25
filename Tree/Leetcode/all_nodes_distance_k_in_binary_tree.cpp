// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/


/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*> mapping;
    
    void mappingparent(TreeNode* root){
        queue<TreeNode*> gg;
        gg.push(root);
        
        while(gg.size() != 0){
            TreeNode* temp = gg.front();
            gg.pop();
            
            if(temp->left != NULL){
                mapping[temp->left] = temp;
                gg.push(temp->left);
            }
            
            if(temp->right != NULL){
                mapping[temp->right] = temp;
                gg.push(temp->right);
            } 
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mappingparent(root);
        
        unordered_map<TreeNode* , bool> visited;
        
        queue<TreeNode*> gg;
        queue<TreeNode*> temp;
        gg.push(target);
        visited[target] = true;
        
        while(gg.size() != 0){

            int gsize = gg.size();
            temp = gg;
            for(int i = 0; i<gsize ; i++ ){
                cout<<temp.front()->val;
                temp.pop();
            }
            cout<<endl;

            k--;
            if(k==-1){
                break;
            }
            
            for(int i = 0; i<gsize ; i++ ){
                TreeNode* temp = gg.front();
                gg.pop();
                if(temp->left != NULL && !visited[temp->left]){
                    gg.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right != NULL && !visited[temp->right]){
                    gg.push(temp->right);
                    visited[temp->right] = true;
                }
                if(mapping.find(temp) != mapping.end() && !visited[mapping[temp]]){
                    gg.push(mapping[temp]);
                    visited[mapping[temp]] = true;
                }
            }
        }
        int xd = gg.size();
        vector<int> result;
        for(int i = 0 ; i < xd ; i++){
            TreeNode* temp = gg.front();
            gg.pop();
            result.push_back(temp->val);
        }
        
        return result;
    }
};
