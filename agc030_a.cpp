//AtCoder AGC030 A - Poisonous Cookies
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C; cin>>A>>B>>C;
    ll c=min(C,A+B+1);
    ll ans=B+c;
    cout<<ans<<endl;
    return 0;
}