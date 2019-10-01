//https://atcoder.jp/contests/abc140/tasks/abc140_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin>>N;
    vector<ll> an(N+1);
    vector<ll> bn(N+1);
    vector<ll> cn(N);
    FOR(i,1,N+1){
        cin>>an[i];
    }
    FOR(i,1,N+1){
        cin>>bn[i];
    }
    FOR(i,1,N){
        cin>>cn[i];
    }

    ll prev_r=-100;
    ll ans= 0;
    FOR(i,1,N+1){
        auto r = an[i];
        ans += bn.at(r);
        if(prev_r+1==r){
            ans += cn.at(prev_r);
        }
        prev_r = r;
    }
    cout<<ans<<endl;
    return 0;
}