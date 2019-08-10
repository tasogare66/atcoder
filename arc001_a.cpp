//https://atcoder.jp/contests/arc001/tasks/arc001_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    string cn; cin>>cn;
    unordered_map<ll,ll> tbl = {
        {'1',0},{'2',0},{'3',0},{'4',0},
    };
    for(const auto& c: cn){
        ++tbl[c];
    }    
    ll ansmax=0,ansmin=INT64_MAX;
    for(const auto&t :tbl){
        ansmax=max(t.second,ansmax);
        ansmin=min(t.second,ansmin);
    }
    cout<<ansmax<<" "<<ansmin<<endl;
    return 0;
}