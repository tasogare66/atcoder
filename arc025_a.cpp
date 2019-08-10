//https://atcoder.jp/contests/arc025/tasks/arc025_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> d7(7);
    vector<ll> j7(7);
    for(auto&& d:d7){
        cin>>d;
    }
    for(auto&& j:j7){
        cin>>j;
    }
    ll ans=0;
    REP(i,7){
        ans+=max(d7[i],j7[i]);
    }
    cout<<ans<<endl;
    return 0;
}