//https://atcoder.jp/contests/past201912-open/tasks/past201912_f
//F - DoubleCamelCase Sort
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
#include <iostream>
#include <cstdlib>

#include <algorithm>
#include <string>
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif    
    string S; cin>>S;
    vector<pair<string,string>> tbl;
    string f;
    FOR(i,0,S.size()){
        auto c = S.at(i);
        f.push_back(S.at(i));
        //大文字?
        if (c<'a'&&f.size()>1){
            string s = f;
            std::transform(f.cbegin(), f.cend(), f.begin(), [](unsigned char uc){ return std::tolower(uc); } );
            tbl.push_back({f,s});
            f.clear();
        }
    }

    sort(tbl.begin(),tbl.end());
    for(auto&& s:tbl){
        cout<<s.second;
    }
    cout<<endl;

    return 0;
}