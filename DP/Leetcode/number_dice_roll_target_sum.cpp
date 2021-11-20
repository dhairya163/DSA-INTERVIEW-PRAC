//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/

class Solution {
public:
    int dp[1001][31];
    int mod=1e9+7;
    int combinations(int d,int f,int target){
        if(d<0){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(d==0 && target==0){
            return 1;
        }
        if(dp[target][d]!=-1){
            return dp[target][d];
        }
        int m=0;
        for(int i=1;i<=f;i++){
            m=(m+combinations(d-1,f,target-i))%mod;
            }
        return dp[target][d]=m;
    }
        
        
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return combinations(d,f,target);       
    }
};
