//https://atcoder.jp/contests/ddcc2017-qual/tasks/ddcc2017_qual_a
//A - DDCC型文字列
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
    if (S.at(0)==S.at(1)&&
    S.at(1)!=S.at(2)&&
    S.at(2)==S.at(3)){
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}