//https://atcoder.jp/contests/abc148/tasks/abc148_e
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
    ll N=100; cin>>N;
    if(N%2!=0){
        cout<<0<<endl;
        return 0;
    }
#if 0
    ll tmp=0;
    auto count = [](ll iv){
        ll v=iv;
        ll cnt=0;
        while(v%5==0){
            ++cnt;
            v/=5;
        }
        dump(iv,cnt);
        return cnt;
    };
    for(ll i=2;i<=N;i+=2){
        if (i%5==0)tmp+=count(i);
    }
    dump(tmp);
#endif
    ll ans=0;
    ll div5=10;
    while(true){
        ll ad=(N/div5);
        if(ad<=0)break;
        ans += ad;
        div5 *= 5;
    }
    cout<<ans<<endl;
    return 0;
}