//https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_a
//A - 最大の和
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n,k; cin>>n>>k;
    vector<ll> an(n);
    for(auto&& a:an){
        cin>>a;
    }
    vector<ll> sums;
    ll sum=0;
    sums.push_back(0);
    for(const auto& a:an){
        sum += a;
        sums.push_back(sum);
    }
    ll ans=INT64_MIN;
    FOR(i,0,n-k+1){
        ll val=sums.at(i+k)-sums.at(i);
        dump(val);
        ans = max(val,ans);
    }    
    cout<<ans<<endl;
    return 0;
}