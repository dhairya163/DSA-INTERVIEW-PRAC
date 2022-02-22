//https://leetcode.com/problems/maximum-width-of-binary-tree/

/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , int>> gg;
        gg.push({root,0});
        
        int ans=0;
        
        while(gg.size() != 0){
            int qsize = gg.size();
            int minn = gg.back().second;
            int first , second;
            for(int i = 0 ; i < qsize ; i++){
                int currid = gg.front().second - minn;
                TreeNode* temp = gg.front().first;
                gg.pop();
                if(temp->left != NULL){
                    gg.push({temp->left,2*currid + 1});
                }
                if(temp->right!=NULL){
                    gg.push({temp->right,2*currid + 2});
                }
                if(i==0){
                    first = currid;
                }
                if(i==qsize-1){
                    second = currid;
                }
            }
            ans = max(ans , second - first + 1);
        }
        return ans;
    }
};
