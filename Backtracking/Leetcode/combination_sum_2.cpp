// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        findCombination(0,candidates,res,ans,target);
        return res;
    }
    void findCombination(int idx,vector<int>&candidates,vector<vector<int>>&res,vector<int>&ans,int target){
        if(target==0){
            res.push_back(ans);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            ans.push_back(candidates[i]);
            findCombination(i+1,candidates,res,ans,target-candidates[i]);
            ans.pop_back();
        }
    }
};
