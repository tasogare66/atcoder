//https://www.hackerrank.com/contests/yfkpo3-2/challenges/new-comers
//New Comers
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
    ll A,B,C; cin>>A>>B>>C;
    unordered_map<string,ll> lst;
    REP(i,A){
        string s; cin>>s;
        lst[s]=1;
    }
    REP(i,B){
        string s; cin>>s;
        lst[s]=1;
    }
    ll ans=0;
    REP(i,C){
        string s; cin>>s;
        if(lst.count(s)==0)++ans;
    }
    cout<<ans<<endl;
    return 0;
}