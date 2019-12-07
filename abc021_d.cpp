//https://atcoder.jp/contests/abc021/tasks/abc021_d
//D - 多重ループ
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll n,k; cin>>n>>k;
    ll ans=0;
    FOR(i,1,n+1){
        ll tmp = pow(i,k-1);
        dump(tmp);
        ans += tmp;
    }    
    cout<<ans<<endl;
    return 0;
}