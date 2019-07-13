//AtCoder ABC121 B - Can you solve this?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M,C; cin>>N>>M>>C;
    vector<ll> bm(M);
    for(auto&& b:bm){
        cin>>b;
    }
    vector<vector<ll>> anm(N,vector<ll>(M));
    for(auto&& am:anm){
        REP(i,M){
            cin>>am[i];
        }
    }
    ll ans=0;
    REP(n,N){
        ll val=C;
        REP(m,M){
            val+=(anm[n][m]*bm[m]);
        }
        if(val>0)++ans;
    }
    cout<<ans<<endl;
    return 0;
}