//https://atcoder.jp/contests/past201912-open/tasks/past201912_b
//B - 増減管理 / Up and Down
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
    FOR(i,1,an.size()){
        ll diff=an.at(i)-an.at(i-1);
        if(diff==0) cout<<"stay"<<endl;
        else if(diff<0) cout<<"down "<<abs(diff)<<endl;
        else cout<<"up "<<abs(diff)<<endl;
    }
    return 0;
}