#include <bits/stdc++.h>
using namespace std;

vector<string> permutations(string processed,string unprocessed){
    vector<string> final;
    if(unprocessed.size()==0){
        vector<string> temp;
        temp.push_back(processed);
        return temp;
    }
    for(int i=0;i<=processed.size();i++){
        string temp = processed.substr(0,i)+unprocessed[0]+processed.substr(i);
        vector<string> result;
        result=permutations(temp,unprocessed.substr(1));
        final.insert(final.end(),result.begin(),result.end());
    }
    return final;
}


int main(){
    vector<string> result;
    result=permutations("","abc");
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
