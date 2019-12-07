//https://atcoder.jp/contests/abc146/tasks/abc146_b
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
    ll N; cin>>N;
    string S; cin>>S;    
    string ans;

    auto replace=[&](char c){
        char r=c+N;
        if(r>'Z')r-=26;
        return r;
    };

    dump(replace('A'));
    dump(replace('Y'));

    for(auto&& c:S){
        ans.push_back(replace(c));
    }
    cout<<ans<<endl;
    return 0;
}