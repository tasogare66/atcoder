//https://atcoder.jp/contests/abc095/tasks/arc096_a
//AtCoder ABC095 
//C - Half and Half
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
    ll A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    ll ans=A*X+B*Y;
    ll cnum=2;
    while(true){
        ll tmp=A*max(X-cnum/2,0LL)+B*max(Y-cnum/2,0LL)+cnum*C;
        if(ans > tmp){
            ans=tmp;
            cnum+=2;
        } else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}