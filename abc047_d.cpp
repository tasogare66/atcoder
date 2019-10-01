//https://atcoder.jp/contests/abc047/tasks/arc063_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,T; cin>>N>>T;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll minv=INT32_MAX;
    ll maxv=0;
    vector<ll> profit(N,0);
    for(ll i=N-1;i>=0;--i){
        ll a=an.at(i);
        minv = min(minv, a);
        maxv = max(maxv, a);
        profit.at(i)=maxv-a;
    }
    sort(profit.begin(),profit.end(),greater<ll>());
    ll ans=0;
    ll p0 = profit.at(0);
    for(const auto& p:profit){
        if (p==p0) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}