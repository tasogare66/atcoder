//https://atcoder.jp/contests/arc032/tasks/arc032_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    ll tmp=0;
    for(ll i=1;i<100;++i){
        tmp+=i;
        cout<<tmp<<endl;
    }
    return 0;
#endif    
    ll n; cin>>n;
    cout<<(n==2?"WANWAN":"BOWWOW")<<endl;
    return 0;
}