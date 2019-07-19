//https://atcoder.jp/contests/agc023/tasks/agc023_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    for(ll i=1;i<=N;++i){
        cin>>an[i];
    }
    vector<ll> sum(N+1,0);
    ll cur=0;
    for(ll i=1;i<=N;++i){
        cur+=an[i];
        sum[i]=cur;
    }
    sort(sum.begin(),sum.end());
    unordered_map<ll,ll> tbl;
    for(const auto& v:sum){
        ++tbl[v];
    }
    ll ans=0;
    for(auto& t: tbl){
        if(t.second>=2){
            ans += t.second*(t.second-1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}