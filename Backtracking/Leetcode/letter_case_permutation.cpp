// https://leetcode.com/problems/letter-case-permutation/

// Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

class Solution {
public:
    vector<string> permutations(string processed , string unprocessed){
        if(unprocessed.size()==0){
            vector<string> temp;
            temp.push_back(processed);
            return temp;
        }
        char ch = unprocessed[0];
        vector<string> first;
        if(isalpha(ch)){
            ch=tolower(ch);
            first = permutations(processed+ch,unprocessed.substr(1));
            vector<string> second = permutations(processed+(char)toupper(ch),unprocessed.substr(1));
            first.insert(first.end(),second.begin(),second.end());
        }
        else{
            vector<string> third = permutations(processed+ch,unprocessed.substr(1));
            first.insert(first.end(),third.begin(),third.end());
        }
        return first;
    }
    
    
    vector<string> letterCasePermutation(string s) {
        return permutations("",s);
    }
};
