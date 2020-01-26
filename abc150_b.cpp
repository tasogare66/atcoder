//https://atcoder.jp/contests/abc150/tasks/abc150_b
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
    string S; cin>>S;
    ll ans=0;
    FOR(i,0,S.size()){
        if (i+1>=S.size()||i+2>=S.size()) continue;
        if(S[i]=='A'&&S[i+1]=='B'&&S[i+2]=='C') ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
