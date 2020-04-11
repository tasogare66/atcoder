//https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
//B - AtCoder Market
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
    vector<ll> an(N),bn(N);
    ll ab_sum=0;
    FOR(i,0,N){
        cin>>an.at(i)>>bn.at(i);
        ab_sum += abs<ll>(an.at(i)-bn.at(i));
    }
    auto search = [](const auto& v){
        ll ret=INT64_MAX;
        for(auto& a:v ){
            ll sum=0;
            for(auto& b:v){
                sum += abs(b-a);
            }
            ret=min(sum,ret);
        }
        return ret;
    };

    ll ans=ab_sum;
    ans += search(an);
    ans += search(bn);
    cout<<ans<<endl;
    return 0;
}