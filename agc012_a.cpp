//https://atcoder.jp/contests/agc012/tasks/agc012_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> a3n(3*N);
    for(auto&& a:a3n){
        cin>>a;
    }
    sort(a3n.begin(),a3n.end(),greater<ll>());
    ll ans=0;
    for(ll i=0;i<N;++i){
        ll idx=2*i+1;
        ans+=a3n[idx];
    }
    cout<<ans<<endl;
    return 0;
}