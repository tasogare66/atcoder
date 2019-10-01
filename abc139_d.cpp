//https://atcoder.jp/contests/abc139/tasks/abc139_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll ans=(1+(N-1))*(N-1)/2;
    cout<<ans<<endl;
    return 0;
}