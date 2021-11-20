#include <bits/stdc++.h>
using namespace std;

vector<string> combinations(string p,int target){
    vector<string> final;
    if(target==0){
        vector<string> temp;
        temp.push_back(p);
        return temp;
    }
    for(int i=1;i<7;i++){
        if(i<=target){
            vector<string> result =combinations(p+to_string(i),target-i);
            final.insert(final.end(),result.begin(),result.end());
        }
    }
    return final;
}

int main(){
    vector<string> answer;
    answer=combinations("",3);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
}
