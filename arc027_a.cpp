//https://atcoder.jp/contests/arc027/tasks/arc027_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll h,m; cin>>h>>m;
    ll lim=18*60;
    ll ans=lim-(h*60+m);
    cout<<ans<<endl;
    return 0;
}