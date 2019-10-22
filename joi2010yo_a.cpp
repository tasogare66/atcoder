//https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_a
//A - レシート
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll ttl; cin>>ttl;
    vector<ll> val(9);
    for(auto&& v:val){
        cin>>v;
    }
    ll ans=ttl-accumulate(val.begin(),val.end(),0);
    cout<<ans<<endl;
    return 0;
}