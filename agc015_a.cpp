//https://atcoder.jp/contests/agc015/tasks/agc015_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,A,B; cin>>N>>A>>B;
    ll min=A*(N-1)+B;
    ll max=B*(N-1)+A;
    ll ans=max-min+1;
    cout<<std::max<ll>(ans,0)<<endl;
    return 0;
}