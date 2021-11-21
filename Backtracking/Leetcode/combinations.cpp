// https://leetcode.com/problems/combinations

//Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// Need to optimise the code as only 5% better.

class Solution {
public:
    vector<vector<int>> combinations(int start,vector<int> processed,int n,int k){
        vector<vector<int>> final;
        if(k<0){
            vector<vector<int>> temp;
            return temp;
        }
        if(k==0){
            vector<vector<int>> temp;
            temp.push_back(processed);
            return temp;
        }
        for(int i=start;i<=n;i++){
            vector<int> p;
            p=processed;
            p.push_back(i);
            vector<vector<int>> result = combinations(i+1,p,n,k-1);
            final.insert(final.end(),result.begin(),result.end());
        }
        return final;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        return combinations(1,temp,n,k);
    }
};
