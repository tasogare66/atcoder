//https://atcoder.jp/contests/abc135/tasks/abc135_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;
    ll l=A*A-B*B;
    ll r=2*(A-B);
    ll k=l/r;
    if(abs(A-k)==abs(B-k)) cout<<k<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}