//https://atcoder.jp/contests/agc009/tasks/agc009_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N),bn(N);
    REP(i,N){
        cin>>an[i];
        cin>>bn[i];
    }
    ll ans=0;
    for(ll i=N-1;i>=0;--i){
        ll a=an[i]+ans;
        ll b=bn[i];
        ll r=(a+b-1)/b;
        ans += r*b-a;
    }
    cout<<ans<<endl;
    return 0;
}