//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll y; cin>>y;
    ll ret=1000-y;
    vector<ll> tbl={500,100,50,10,5,1};
    ll ans=0;
    for(const auto& c:tbl){
        auto n = ret / c;
        ans += n;
        ret -= n*c;
    }
    cout<<ans<<endl;
    return 0;
}