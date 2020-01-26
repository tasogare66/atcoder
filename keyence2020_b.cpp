//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
//B - Robot Arms
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
    vector<pair<ll,ll>> xln(N);
    for(auto& xl:xln){
        ll x,l; cin>>x>>l;
        ll st=x-l;
        ll ed=x+l;
        xl.first=ed;
        xl.second=st;
    }
    sort(xln.begin(),xln.end());
    ll ans=0;
    ll pt=INT64_MIN;
    for(auto& xl:xln){
        if(pt<=xl.second){
            ++ans;
            pt=xl.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}