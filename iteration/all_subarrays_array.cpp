#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> nottaken;
    vector<int> input = {1,2,3};
    vector<int> empty;
    nottaken.push_back(empty);
    for(int i=0;i<input.size();i++){
        int temp=nottaken.size();
        for(int j=0;j<temp;j++){
            vector<int> tempvec;
            tempvec.push_back(input[i]);
            tempvec.insert(tempvec.begin(),nottaken[j].begin(),nottaken[j].end());
            nottaken.push_back(tempvec);
        }
    }
    for(int i=0;i<nottaken.size();i++){
        for(int j=0;j<nottaken[i].size();j++){
            cout<<nottaken[i][j]<<" ";
        }
        cout<<endl;
    }
}
