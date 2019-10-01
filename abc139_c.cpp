//https://atcoder.jp/contests/abc139/tasks/abc139_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> hn(N);
    for(auto&& h:hn){
        cin>>h;
    }
    ll ans=0;
    ll cnt=0;
    for(ll i=0;i<N-1;++i){
        if(hn[i]>=hn[i+1]){
            ++cnt;
        } else {
            cnt=0;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}