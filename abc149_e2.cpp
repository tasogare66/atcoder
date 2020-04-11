//https://atcoder.jp/contests/abc149/tasks/abc149_e
//E - Handshake,2回目
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
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M;cin>>N>>M;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    //累積和
    vector<ll> sums(N+1);
    FOR(i,0,an.size()){
        sums.at(i+1) = sums.at(i) + an.at(i);
    }

    auto check_func = [&](ll v){
        ll count=0;//回数
        FOR(i,0,an.size()){
            ll x=an.at(i);
            ll y=v-x;
            auto it = lower_bound(an.begin(), an.end(), y);
            count += distance(it, an.end());
        }
        //dump(count);
        return (count>=M);
    };

    ll lb=1,ub=1e+10+7;
    while(ub-lb>1){
        ll mid = (ub+lb)/2;
        auto ck = check_func(mid);
        if (ck){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    dump(lb);

    ll ans=0;
    ll count = 0;
    FOR(i,0,an.size()){
        ll x=an.at(i);
        ll y=lb-x;
        auto it = lower_bound(an.begin(), an.end(), y);
        ll num = distance(it, an.end());
        ans += num * x;
        ans += sums.at(N) - sums.at(N-num);
        count += num;
    }
    if(count>M) ans -= lb*(count-M);
    cout<<ans<<endl;

    return 0;
}