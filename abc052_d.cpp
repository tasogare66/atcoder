//https://atcoder.jp/contests/abc052/tasks/arc067_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N, A, B; cin>>N>>A>>B;
    vector<ll> xn(N);
    for(auto&& x:xn){
        cin>>x;
    }
    ll ans=0;
    ll now=0;
    FOR(i,1,xn.size()){
        auto len = xn.at(i) - xn.at(now);
        ans += min(len*A,B);
        now=i;
    }
    cout<<ans<<endl;
    return 0;
}