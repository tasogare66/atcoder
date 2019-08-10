//https://atcoder.jp/contests/arc033/tasks/arc033_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll ans=0;
    for(ll i=1;i<=N;++i){
        ans+=N-i+1;
    }
    cout<<ans<<endl;
    return 0;
}