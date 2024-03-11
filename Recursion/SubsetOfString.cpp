#include<bits/stdc++.h>
using namespace std;

void subsets(string& s, string curr, int i){
    if(i == s.length()){
        cout<<curr<<endl;
        return;
    }
    subsets(s, curr+s[i], i+1);
    subsets(s, curr, i+1);
}

int main(){

    string s = "ABC";
    // cin>>s;
    subsets(s, "", 0);

    return 0;
}