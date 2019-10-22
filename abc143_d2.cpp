//https://atcoder.jp/contests/abc143/tasks/abc143_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> ln(N);
    for(auto&& l:ln){
        cin>>l;
    }
    sort(ln.begin(),ln.end());
    ll ans=0;
    REP(i,N){
        ll a=ln.at(i);
        FOR(j,i+1,N){
            ll b=ln.at(j);
            FOR(k,j+1,N){
                ll c=ln.at(k);
                if(a+b>c){
                    ++ans;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}