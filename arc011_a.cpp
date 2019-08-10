//https://atcoder.jp/contests/arc011/tasks/arc011_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll m,n,N; cin>>m>>n>>N;
    ll ans=0;
    ll r= 0;
    do {
        ans+=N;
        r+=N;
        ll tmp=r/m;
        r-=(tmp)*m;
        N=(tmp)*n;
    } while(N>0);
    cout<<ans<<endl;
    return 0;
}