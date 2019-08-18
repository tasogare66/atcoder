//https://atcoder.jp/contests/abc137/tasks/abc137_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;
    ll ans=max(A+B,A-B);
    ans=max(ans,A*B);
    cout<<ans<<endl;    
    return 0;
}