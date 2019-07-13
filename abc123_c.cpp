//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> tbl(5);
    ll mint=INT64_MAX;
    for(auto&& t:tbl){
        cin>>t;
        mint=min(t,mint);
    }
    ll ans=5+N/mint;
    cout<<ans<<endl;
    return 0;
}