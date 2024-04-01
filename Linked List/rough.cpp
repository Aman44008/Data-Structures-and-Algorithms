#include<bits/stdc++.h>
using namespace std;



int main(){

    // int n;
    // cin>>n;

    // for(int i = 1; i <= n+1; i++){
    //     for(int j = 1; j <= (n-i+1); j++){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<endl;
    // }

    int arr[] = {4,1,2,3,3,5,6};
    int ans = 0;
    for(int i = 0; i < 7; i++){
        ans ^= arr[i]; 
    }
    cout<<ans;
    return 0;
}