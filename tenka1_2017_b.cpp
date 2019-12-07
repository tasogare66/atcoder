//https://atcoder.jp/contests/tenka1-2017-beginner/tasks/tenka1_2017_b
//B - Different Distribution
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
    vector<pair<ll,ll>> abn(N);
    for(auto&& ab:abn){
        cin>>ab.first>>ab.second;
    }
    sort(abn.begin(),abn.end());
    auto b=*(abn.end()-1);
    cout<<(b.first+b.second)<<endl;
    return 0;
}