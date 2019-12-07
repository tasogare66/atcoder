//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d
//D - Crossing
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
    bool yn=false;
    FOR(i,3,1e+5){
        ll tmp=i*(i-1)/2;
        if(tmp==N) yn=true;
        if(tmp>N) break;
    }
    cout<<(yn?"Yes":"No")<<endl;
    if(yn){

    }
    return 0;
}