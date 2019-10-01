//https://atcoder.jp/contests/abc141/tasks/abc141_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    // vector<ll> an(N);
    // for(auto&& a:an){
    //     cin>>a;
    // }
    priority_queue<ll> an;
    REP(i,N){
        ll a; cin>>a;
        an.push(a);
    }
    for(ll i=0;i<M;++i){
        ll tmp = an.top(); an.pop();
        tmp /= 2; 
        an.push(tmp);
    }
    ll ans= 0;
    while(!an.empty()){
        ans += an.top(); an.pop();
    }
    cout<<ans<<endl;
    return 0;
}