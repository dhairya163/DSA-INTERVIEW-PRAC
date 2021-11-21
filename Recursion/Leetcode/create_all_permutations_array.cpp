// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> solve(vector<int> processed , vector<int> unprocessed){
        vector<vector<int>> final;
        
        if(unprocessed.size()==0){
            vector<vector<int>> temp;
            temp.push_back(processed);
            return temp;
        }
        
        for(int i=0;i<=processed.size();i++){
            vector<int> p;
            for(int j=0;j<i;j++){
                p.push_back(processed[j]);
            }
            p.push_back(unprocessed[0]);
            for(int j=i;j<processed.size();j++){
                p.push_back(processed[j]);
            }
            vector<int> up;
            for(int k=1;k<unprocessed.size();k++){
                up.push_back(unprocessed[k]);
            }
            vector<vector<int>> result = solve(p,up);
            final.insert(final.end(),result.begin(),result.end());
        }
        return final;
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        return solve(temp,nums);        
    }
};
