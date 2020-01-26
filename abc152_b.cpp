//https://atcoder.jp/contests/abc152/tasks/abc152_b
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
    string a,b; cin>>a>>b;
    ll ai = std::stoi(a);
    ll bi = std::stoi(b);     
    vector<string> ans;

    string tmp;
    REP(i,ai){
        tmp += b;
    }
    ans.push_back(tmp);
    tmp="";
    REP(i,bi){
        tmp += a;
    }
    ans.push_back(tmp);

    sort(ans.begin(),ans.end());
    cout<<ans[0]<<endl;
    return 0;
}