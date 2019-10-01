//https://atcoder.jp/contests/abc139/tasks/abc139_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;    
    ll num=1;
    ll ans=0;
    while(num<B){
        num-=1;
        num+=A;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}