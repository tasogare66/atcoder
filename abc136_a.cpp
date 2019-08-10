//https://atcoder.jp/contests/abc136/tasks/abc136_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C; cin>>A>>B>>C;    
    ll ans=C-(A-B);
    cout<<max(ans,(ll)0)<<endl;
    return 0;
}