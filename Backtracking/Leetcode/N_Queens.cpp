// https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> final;
    
    bool dp[9][9];
    bool issafe(int row,int col,int n){
        int i=row-1;
        int j=col;
        while(i>=0){
            if(dp[i][j]==false){
                return false;
            }
            i--;
        }
        
        i=row-1;
        j=col-1;
        while(i>=0 && j>=0){
            if(dp[i][j]==false){
                return false;
            }
            i--;
            j--;
        }
        
        i=row-1;
        j=col+1;
        while(i>=0 && j<n){
            if(dp[i][j]==false){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    
    int solution(int n,int row,int col,int k){
        int m = 0;
        if(k==0){
            vector<string> temp;
            for(int y=0;y<n;y++){
                string gg;
                for(int z=0;z<n;z++){
                    if(dp[y][z]==true){
                        gg.push_back('.');
                    }
                    else{
                        gg.push_back('Q');
                    }
                }
                temp.push_back(gg);
            }
            final.push_back(temp);
            return 1;
        }
        for(int i=0;i<n;i++){
            if(dp[row][i]==true && issafe(row,i,n)){
                dp[row][i]=false;
                m = m + solution(n,row+1,i,k-1);
                dp[row][i]=true;
            }
        }
        return m;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        memset(dp,true,sizeof(dp));
        int count = solution(n,0,0,n);
        return final;
    }
};
