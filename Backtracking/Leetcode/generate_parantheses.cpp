// https://leetcode.com/problems/generate-parentheses/

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
public:
    vector<string> permutations(int n,int o,int c,string &processed){
        if(o<c){
            vector<string> temp;
            return temp;  
        }
        if(o>n || c>>n){
            vector<string> temp;
            return temp;
        }
        if(o==n && c==n){
            vector<string> temp;
            temp.push_back(processed);
            return temp;
        }
        processed.push_back('(');
        vector<string> first = permutations(n,o+1,c,processed);
        processed.pop_back();
        processed.push_back(')');
        vector<string> second = permutations(n,o,c+1,processed);
        processed.pop_back();
        first.insert(first.end(),second.begin(),second.end());
        return first;
    }
    
    
    vector<string> generateParenthesis(int n) {
        string temp = "";
        return permutations(n,0,0,temp);
    }
};
