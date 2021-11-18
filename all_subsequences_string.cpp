#include <bits/stdc++.h>
using namespace std;

vector<string> subseq(string unprocessed,string processed){
    if(unprocessed.size()==0){
        vector<string> temp;
        temp.push_back(processed);
        return temp;
    }
    char ch = unprocessed[0];
    vector<string> left = subseq(unprocessed.substr(1),processed+ch);
    vector<string> right = subseq(unprocessed.substr(1),processed);
    left.insert(left.end(),right.begin(),right.end());
    return left;
}

int main() {
	vector<string> temp = subseq("abc","");
	for(int i=0;i<temp.size();i++){
	    cout<<temp[i]<<endl;
	}
	return 0;
}
