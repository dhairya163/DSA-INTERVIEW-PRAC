// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> gg;
        map<int,map<int,multiset<int>>> nodes;
        
        gg.push({root,{0,0}});
        
        while( gg.size() != 0){
            auto temp = gg.front();
            gg.pop();
            
            int x = temp.second.first;
            int y = temp.second.second;
            
            TreeNode* tempnode = temp.first;
            
            nodes[x][y].insert(tempnode->val);
            
            if(tempnode->left != NULL){
                gg.push( { tempnode->left , {x - 1, y + 1} });
            }
            if(tempnode->right != NULL){
                gg.push( {tempnode->right , {x+1 , y+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> result;
            for(auto q : p.second){
                result.insert(result.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(result);
        }
        return ans;
    }
};
