//https://atcoder.jp/contests/agc024/tasks/agc024_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll a,b,c,k; cin>>a>>b>>c>>k;
    ll ans=(k%2==1)?b-a:a-b;
    cout<<ans<<endl;    
    return 0;
}