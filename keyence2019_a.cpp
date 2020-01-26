//https://atcoder.jp/contests/keyence2019/tasks/keyence2019_a
//A - Beginning
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N1,N2,N3,N4; cin>>N1>>N2>>N3>>N4;
    map<ll,ll> tbl;
    tbl[N1]++;
    tbl[N2]++;
    tbl[N3]++;
    tbl[N4]++;
    if (tbl.count(1)==1
    && tbl.count(9)==1
    && tbl.count(7)
    && tbl.count(4)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
