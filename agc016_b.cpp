//https://atcoder.jp/contests/agc016/tasks/agc016_b
//B - Colorful Hats
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
    vector<ll> an(N);
    for(auto&&a:an){
        cin>>a;
    }
    map<ll,ll> tbl;
    FOR(i,0,N){
        auto a=an.at(i);
        if(a==0){
            tbl[a]++;
            continue;
        }
        auto it=tbl.find(a);
        if (it == tbl.end() || it->second==0){
            //ない
            cout<<"No"<<endl;
            exit(0);
        }
        it->second--;
        tbl[a+1]
    }
    cout<<"Yes"<<endl;
    return 0;
}