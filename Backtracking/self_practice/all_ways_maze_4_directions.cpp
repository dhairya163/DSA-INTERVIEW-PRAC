// You have to reach end of the maze giving the starting index and you can go in all 4 directions which is UP, DOWN, LEFT, RIGHT.
// Here comes the picture of Backtracking , where you go on a particular cell and mark the previous cell as visited so that you do no visit that cell again and when the recursion call is complete you simply revert the cell you marked as visited to not harm the further recursion calls.

#include<bits/stdc++.h>
using namespace std;

bool dp[4][4];

vector<string> ways(string processed,int row,int col,int endrow,int endcol){
    if(row<0 || col<0 || row>endrow || col>endcol){
        vector<string> empty;
        return empty;
    }
    if(row==endrow && col == endcol){
        vector<string> temp;
        temp.push_back(processed);
        return temp;
    }
    if(dp[row][col]==false){
        vector<string> empty;
        return empty;
    }
    dp[row][col]=false;
    vector<string> down = ways(processed+'D',row+1,col,endrow,endcol);
    vector<string> right = ways(processed+'R',row,col+1,endrow,endcol);
    vector<string> left = ways(processed+'L',row,col-1,endrow,endcol);
    vector<string> up = ways(processed+'U',row-1,col,endrow,endcol);
    dp[row][col]=true;
    down.insert(down.end(),right.begin(),right.end());
    down.insert(down.end(),left.begin(),left.end());
    down.insert(down.end(),up.begin(),up.end());
    return down;
}


int main(){
    memset(dp,true,sizeof(dp));
    vector<string> result = ways("",0,0,2,2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
