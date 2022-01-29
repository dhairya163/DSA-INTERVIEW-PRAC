// https://leetcode.com/problems/average-of-levels-in-binary-tree/

/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
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
    vector<double> averageOfLevels(TreeNode* root) {
        double avg = 0.00000;
        double count = 0.00000;
        double sum = 0.00000;
        vector<double> ans;
        
        queue<TreeNode*> gg;
        gg.push(root);
        
        while( gg.size() != 0){
            int size = gg.size();
            for(int i = 0 ; i< size;i++){
                TreeNode* temp = gg.front();
                gg.pop();
                sum = sum + temp->val;
                count ++;
                if(temp->left != NULL){
                    gg.push(temp->left);
                }
                if(temp->right != NULL){
                    gg.push(temp->right);
                }
            }
            avg = sum/count;
            ans.push_back(avg);
            sum = 0;
            count = 0;
        }
        
        return ans;
    }
};
