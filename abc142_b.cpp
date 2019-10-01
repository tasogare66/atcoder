//https://atcoder.jp/contests/abc142/tasks/abc142_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,K; cin>>N>>K;
    vector<ll> hn(N);
    ll ans=0;
    for(auto&&h:hn){
        cin>>h;
        if(h>=K)++ans;
    }
    cout<<ans<<endl;    
    return 0;
}