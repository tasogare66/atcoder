//https://atcoder.jp/contests/abc134/tasks/abc134_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,D; cin>>N>>D;
    ll num=2*D+1;
    ll ans=(N+num-1)/num;
    cout<<ans<<endl;
    return 0;
}