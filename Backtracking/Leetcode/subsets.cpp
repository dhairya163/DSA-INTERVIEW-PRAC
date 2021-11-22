// https://leetcode.com/problems/subsets/

// Given an integer array nums of unique elements, return all possible subsets (the power set).

class Solution {
public:
    vector<vector<int>> subsets(vector<int> processed , vector<int> &unprocessed){
        
        if(unprocessed.size()==0){
            vector<vector<int>> temp;
            temp.push_back(processed);
            return temp;
        }
        
        vector<int> up;
        for(int i=1;i<unprocessed.size();i++){
            up.push_back(unprocessed[i]);
        }
        
        vector<vector<int>> nottake = subsets(processed,up);
        processed.push_back(unprocessed[0]);
        vector<vector<int>> take = subsets(processed,up);
            
        take.insert(take.end(),nottake.begin(),nottake.end());
        return take;
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        return subsets(temp,nums);
    }
};
