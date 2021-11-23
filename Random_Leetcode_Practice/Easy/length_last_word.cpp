class Solution {
public:
    int lengthOfLastWord(string s) {
        int last;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                curr++;
                if(i==s.size()-1){
                    last=curr;
                }
            }
            else{
                if(curr!=0){
                    last=curr;
                }
                curr=0;
            }
        }
        return last;
    }
};
