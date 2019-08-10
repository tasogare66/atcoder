//https://atcoder.jp/contests/arc041/tasks/arc041_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll x,y; cin>>x>>y;
    ll k; cin>>k;
    ll ans=0;
    if(y<k){
        ll diff=k-y;
        ans=y+x-diff;
    }else{
        ans=x+k;
    }
    cout<<ans<<endl;
    return 0;
}