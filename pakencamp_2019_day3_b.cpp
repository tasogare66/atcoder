//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_b
//B - 多数決
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
    ll black=0,white=0;
    REP(i,N){
        string s; cin>>s;
        if(s=="black") ++black;
        else ++white;        
    }
    cout<<(black>white?"black":"white")<<endl; 
    return 0;
}