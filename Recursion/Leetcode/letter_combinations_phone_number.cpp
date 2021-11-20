// https://leetcode.com/problems/letter-combinations-of-a-phone-number/


class Solution {
public:
    vector<string> combinations(string unprocessed,string processed){
        vector<string> final;
        if(unprocessed.size()==0){
            vector<string> temp;
            temp.push_back(processed);
            return temp;
        }
        int start;
        int end;
        int digit = unprocessed[0]-'0';
        if(digit<7){
            start = (digit-2)*3;
            end = (digit-1)*3;
        }
        else if(digit==7){
            start = (digit-2)*3;
            end = ((digit-1)*3)+1;            
        }
        else if(digit==8){
            start = ((digit-2)*3)+1;
            end = ((digit-1)*3)+1;  
        }
        else if(digit==9){
            start = ((digit-2)*3)+1;
            end = ((digit-1)*3)+2;  
        }
        for(int i=start;i<end;i++){
            char toadd = (char)'a' + i;
            vector<string> result =combinations(unprocessed.substr(1),processed+toadd);
            final.insert(final.end(),result.begin(),result.end());
        }
        return final;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> a;
        if(digits.size()==0){
            return a;
        }
        a=combinations(digits,"");
        return a;
    }
};
