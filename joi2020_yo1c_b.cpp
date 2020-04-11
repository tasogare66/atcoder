//https://atcoder.jp/contests/joi2020yo1c/tasks/joi2020_yo1c_b
//B - キャピタリゼーション (Capitalization)
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
    auto check_func = [&](ll p) {
        string joi="joi";
        if(p+2>=S.size()) return;
        if(S.at(p)==joi.at(0)
        &&S.at(p+1)==joi.at(1)
        &&S.at(p+2)==joi.at(2))
        {
            S.at(p)='J';
            S.at(p+1)='O';
            S.at(p+2)='I';
        }
    };
    FOR(i,0,S.size()){
        check_func(i);
    }    
    cout<<S<<endl;
    return 0;
}