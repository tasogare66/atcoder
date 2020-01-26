//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_b
//B - Touitsu
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
    ll N; cin>>N;
    string A,B,C; cin>>A>>B>>C;
    ll ans=0;
    FOR(i,0,N){
        auto c0=A.at(i);
        auto c1=B.at(i);
        auto c2=C.at(i);
        if(c0==c1&&c1==c2){
        }else if(c0!=c1&&c0!=c2&&c1!=c2){
            ans+=2;
        }else{
            ans+=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}