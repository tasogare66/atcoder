//https://atcoder.jp/contests/agc031/tasks/agc031_b
//B - Reversi
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
constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> cn(N+1);
    vector<ll> cn2; cn2.reserve(N+1); //重複部分を消したもの
    cn2.push_back(1);
    FOR(i,1,N+1){
        ll c; cin>>c;
        cn.at(i)=c;
        if (cn.at(i-1)!=cn.at(i)) cn2.push_back(c);
    }
    unordered_map<ll,ll> colnum;
    vector<ll> ansv(cn2.size());
    ansv[0]=1;
    FOR(i,1,cn2.size()){
        auto c=cn2.at(i);
        auto& m = colnum[c];
        ansv[i] = (ansv[i-1] + m)%MOD;
        m = (m + ansv[i-1])%MOD;
    }    
    cout<<ansv.back()<<endl;
    return 0;
}