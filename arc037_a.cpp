//https://atcoder.jp/contests/arc037/tasks/arc037_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> mn(N);
    for(auto&& m:mn){
        cin>>m;
    }
    ll ans=0;
    REP(i,mn.size()){
        ans+=max(80-mn[i],(ll)0);
    }
    cout<<ans<<endl;
    return 0;
}