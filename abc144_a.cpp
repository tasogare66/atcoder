//https://atcoder.jp/contests/abc144/tasks/abc144_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;
    if(A>=1&&A<=9&&B>=1&&B<=9) cout<<A*B<<endl;
    else cout<<-1<<endl;
    return 0;
}