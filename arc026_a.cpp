//https://atcoder.jp/contests/arc026/tasks/arc026_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,A,B; cin>>N>>A>>B;
    ll bnum=min((ll)5,N);
    ll ans=(N-bnum)*A+bnum*B;
    cout<<ans<<endl;
    return 0;
}