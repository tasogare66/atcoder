//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_c
//C - 桁和 (Digit Sum)
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
    ll N=2019; cin>>N;
    auto keta_sum = [](ll v){
        ll sum=0;
        while(v>0){
            sum+=(v%10);
            v/=10;
        }
        return sum;
    };
    unordered_map<ll,ll> ans;
    ans[N]=1;
    for(ll i=N-1;i>=1;--i){
        ll tmp=i+keta_sum(i);
        if(ans.count(tmp)){
            ans[i]=1;            
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}