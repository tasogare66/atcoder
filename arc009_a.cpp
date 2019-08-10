//https://atcoder.jp/contests/arc009/tasks/arc009_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll sum=0;
    REP(i,N){
        ll a,b; cin>>a>>b;
        sum += a * b;
    }
    ll ans = sum * 1.05;
    cout<<ans<<endl;
    return 0;
}