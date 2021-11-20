// Given Starting and Ending point on maze , you have to print all the possible paths that you can go to reach the end of the maze considering you can move Down and right only.

#include<bits/stdc++.h>
using namespace std;


vector<string> ways(string processed,int row,int col,int endrow,int endcol){
    if(row>endrow || col>endcol){
        vector<string> empty;
        return empty;
    }
    if(row==endrow && col == endcol){
        vector<string> temp;
        temp.push_back(processed);
        return temp;
    }
    vector<string> left = ways(processed+'D',row+1,col,endrow,endcol);
    vector<string> right = ways(processed+'R',row,col+1,endrow,endcol);
    
    left.insert(left.end(),right.begin(),right.end());
    return left;
}


int main(){
    vector<string> result = ways("",0,0,2,2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
