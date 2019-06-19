//AtCoder ABC079 B - Lucas Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    ll dp[86+10]; 
    dp[0]=2;
    dp[1]=1;
    for(ll i=2;i<=N;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }   
    cout<<dp[N]<<endl;
    return 0;
}