// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows , "");
        
        if(numRows == 1)
            return s;
        
        int row=0;
        int dir=1;
        
        for(int i=0; i<s.size(); i++){
            
            temp[row] = temp[row] + s[i];
            
            if(row == numRows - 1){
                dir = -1;
            }
            
            if(row == 0){
                dir = 1;
            }
            
            row = row + dir;
                
        }
        
        string ans="";
        for(int i=0;i<temp.size();i++){
            ans.insert(ans.end(),temp[i].begin(),temp[i].end());
        }       
        return ans;
    }
};
