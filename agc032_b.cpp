//https://atcoder.jp/contests/agc032/tasks/agc032_b
//B - Balanced Neighbors
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
    //完全グラフからいらないところ外す
    vector<pair<ll,ll>> ans;
    if(N%2==1){
        FOR(i,1,N+1){
            ll del_no = N-i;
            FOR(j,i+1,N+1){
                if (j==del_no)continue;
                ans.emplace_back(make_pair(i,j));
            }
        }
    }else{
        FOR(i,1,N+1){
            ll del_no = N-i+1;
            FOR(j,i+1,N+1){
                if (j==del_no)continue;
                ans.emplace_back(make_pair(i,j));
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto& p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}