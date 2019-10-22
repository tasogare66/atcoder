//https://atcoder.jp/contests/abc143/tasks/abc143_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;    
    ll ans=0;
    ans=max(ans,A-2*B);
    cout<<ans<<endl;
    return 0;
}