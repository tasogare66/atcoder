//https://atcoder.jp/contests/abc155/tasks/abc155_c
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
    map<string,ll> tbl;
    ll max =0;
    FOR(i,0,N){
        string s; cin>>s;
        tbl[s]++;
        max=std::max<ll>(tbl[s],max);
    }    
    vector<string> strs;
    for(auto& p:tbl){
        if (p.second==max){
            //auto tmp=p.first;
            strs.emplace_back(p.first);
        }
    }
    sort(strs.begin(),strs.end());
    for(const auto& s:strs){
        cout<<s<<endl;
    }
    //cout<<strs.at(0)<<endl;
    return 0;
}