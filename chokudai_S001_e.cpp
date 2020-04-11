//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_e
//E - 1は何番目？
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
    for(auto&& a:an){
        cin>>a;
    }
    auto it=find(an.begin(),an.end(),1);    
    auto ans=std::distance(an.begin(),it)+1;
    cout<<ans<<endl;
    return 0;
}