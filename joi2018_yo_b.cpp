//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_b
//
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll ans=0;
    ll chain=0;
    for(const auto& a:an){
        if(a) chain++;
        else chain=0;
        ans=max(ans,chain);
    }
    cout<<ans+1<<endl;
    return 0;
}