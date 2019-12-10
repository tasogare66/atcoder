//https://atcoder.jp/contests/abc147/tasks/abc147_c
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;    
    vector<unordered_map<ll,ll>> tbl(N+1);
    FOR(i,1,N+1){
        ll A; cin>>A;
        auto&& t=tbl.at(i);
        REP(j,A){
            ll x,y; cin>>x>>y;
            t[x]=y;
        }
    }
    ll mx=pow(2,N);
    ll ans=0;
    auto count_bit = [&](ll flag) {
        ll ret=0;
        REP(i,N){
            if(flag&(1<<i)) ++ret;
        }
        dump(flag,ret);
        return ret;
    };
    auto check_func = [&](ll flag)->ll{
        REP(i,N){
            if (flag & (1<<i)){ //本当は確認
                const auto& t=tbl.at(i+1);
                for(auto& m:t){
                    ll tmp=(1<<m.first-1);
                    if((bool)(flag&(tmp)) != (bool)m.second) return 0;
                }
            }
        }
        return count_bit(flag);
    };
    dump(check_func(7));
    dump(check_func(3));
    FOR(i,1,mx){
        ans=max(check_func(i),ans);
    }
    cout<<ans<<endl;
    return 0;
}