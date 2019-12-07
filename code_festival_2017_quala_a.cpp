//https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_a
//A - Snuke's favorite YAKINIKU
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
    string tmp="YAKI";
    bool ans=true;
    REP(i,tmp.size()){
        if(i>=S.size() || tmp[i]!=S[i]){
            ans=false;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}