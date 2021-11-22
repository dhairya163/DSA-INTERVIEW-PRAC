// https://leetcode.com/problems/n-queens-ii/

/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
   Given an integer n, return the number of distinct solutions to the n-queens puzzle.  */
   

class Solution {
public:
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
    
    
    int totalNQueens(int n) {
        memset(dp,true,sizeof(dp));
        return solution(n,0,0,n);
    }
};
