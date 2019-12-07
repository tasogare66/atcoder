//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_c
//C - Different Strokes
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
struct Info{
    ll A,B;
    ll dif;
};
int main() {
    ll N; cin>>N;
    vector<Info> abn(N);
    for(auto&& ab:abn){
        cin>>ab.A>>ab.B;
        ab.dif=ab.A-ab.B; //高橋-青木
    }
    return 0;
}