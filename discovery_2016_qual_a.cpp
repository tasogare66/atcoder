//https://atcoder.jp/contests/discovery2016-qual/tasks/discovery_2016_qual_a
//A - DISCO presents ディスカバリーチャンネルプログラミングコンテスト 2016
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
    ll W; cin>>W;
    string s="DiscoPresentsDiscoveryChannelProgrammingContest2016";
    vector<string> ans;
    string tmp;

    auto flush = [&](){
        if(!tmp.empty()){
            ans.push_back(tmp);
        }
        tmp="";
    };

    REP(i,s.size()){
        if(i%W==0) flush();
        tmp.push_back(s.at(i));
    }
    flush();

    for(const auto& st:ans){
        cout<<st<<endl;
    }
    return 0;
}