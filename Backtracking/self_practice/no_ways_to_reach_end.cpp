//Given a start and end of a maze , you have to determine number of ways you can go to reach end consider that you can move only in down or right direction.

#include<bits/stdc++.h>
using namespace std;


int ways(int row,int col,int endrow,int endcol){
    if(row>endrow || col>endcol){
        return 0;
    }
    if(row==endrow && col == endcol){
        return 1;
    }
    int left = ways(row+1,col,endrow,endcol);
    int right = ways(row,col+1,endrow,endcol);
    
    return left+right;
}


int main(){
    cout<<ways(0,0,2,2);
}
