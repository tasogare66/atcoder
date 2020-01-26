//https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_a
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
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<string,ll>> stn;
    FOR(i,0,N){
        string s; cin>>s;
        ll t; cin>>t;
        stn.push_back({s,t});
    }    
    string X; cin>>X;
    bool flag=false;
    ll ans=0;
    for(auto&p:stn){
        dump(p.first, ans);
        if(flag) {
            ans+=p.second;
        }else if(p.first == X) flag=true;
    }
    cout<<ans<<endl;
    return 0;
}