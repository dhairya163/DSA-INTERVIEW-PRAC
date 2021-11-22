// https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    bool dp[16][16];
    int current=0;
    int max=0;
    
    void getMaxGold(vector<vector<int>> &grid , int start , int end ,int n,int m){
        if(start>=n || end>=m || start < 0 || end < 0){
            return;
        }
        if(grid[start][end]!=0 && dp[start][end]==true){
            dp[start][end]=false;
            current = current + grid[start][end];
            if(current>max){
                max=current;
            }
            getMaxGold(grid,start+1,end,n,m);
            getMaxGold(grid,start-1,end,n,m);
            getMaxGold(grid,start,end+1,n,m);
            getMaxGold(grid,start,end-1,n,m);
            current=current-grid[start][end];
            dp[start][end]=true;            
        }
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        memset(dp,true,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                getMaxGold(grid,i,j,n,m);
                }
            }
        }
        return max;
    }
};
