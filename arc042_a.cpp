//https://atcoder.jp/contests/arc042/tasks/arc042_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N, M; cin>>N>>M;
    vector<ll> am(M);
    for(auto&& a:am){
        cin>>a;
    }
    vector<ll> flag(N+1);
    for(ll i=am.size()-1;i>=0;--i){
        ll t=am[i];
        if(flag[t]==false) {
            cout<<t<<endl;
            flag[t]=true;
        }
    }
    for(ll i=1;i<=N;++i){
        if(flag[i]==false) cout<<i<<endl;
    }
    return 0;
}