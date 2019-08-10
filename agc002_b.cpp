//https://atcoder.jp/contests/agc002/tasks/agc002_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    vector<ll> box(N+1,1);
    vector<bool> pr(N+1,false);
    pr[1]=true;
    REP(i,M){
        ll x,y; cin>>x>>y;
        if(pr[x]) pr[y]=true;
        --box[x];
        ++box[y];
        if(box[x]<=0) pr[x]=false;
    }
    ll ans=0;
    for(const auto& p:pr){
        if(p)++ans;
    }
    cout<<ans<<endl;
    return 0;
}