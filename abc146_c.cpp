//https://atcoder.jp/contests/abc146/tasks/abc146_c
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
 #if LOCAL&01
     std::ifstream in("./test/sample-1.in"); //input.txt
     std::cin.rdbuf(in.rdbuf());
 #else
     cin.tie(0);
     ios::sync_with_stdio(false);
 #endif
    ll A,B,X; cin>>A>>B>>X;
    ll lb=0,ub=1e+9+1;
    auto check_func=[&](ll n)->bool{
        ll dn=floor(log10(n)+1);
        return (X>=A*n+B*dn);
    };
    while(ub-lb>1){
        dump(lb,ub);
        ll mid=(ub+lb)/2;
        if(check_func(mid)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    cout<<lb<<endl;
    return 0;
}
int __main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    auto ketav=[](ll k){
        ll r=1;
        FOR(i,1,k){
            r*=10;
        }
        return r;
    };

    ll A,B,X; cin>>A>>B>>X;        
    ll ans=0;
    FOR(k,1,10){//けた
        ll kmin=ketav(k);
        ll kmax=kmin*10-1;
        ll tmp = X - B*k;
        if(tmp>=0){
            ll n=tmp/A;
            if(n>=kmax) n=kmax;
            if(n<kmin) continue;
            if(n>0) {
                ans=max(ans,n);
            }
        }
    }
    //10けた
    ll k=10;
    ll tmp=X-B*k;
    ll n=1e+9;
    if(X>=A*n+B*10){
        ans=n;
    }

    cout<<ans<<endl;
    return 0;
}