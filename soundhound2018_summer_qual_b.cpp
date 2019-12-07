//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_b
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
    string S; cin>>S;
    ll w; cin>>w;
    string ans;
    ans.push_back(S[0]);
    for(ll i=w;i<S.size();i+=w){
        ans.push_back(S[i]);
    }
    cout<<ans<<endl;
    return 0;
}