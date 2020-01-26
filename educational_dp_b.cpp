//https://atcoder.jp/contests/dp/tasks/dp_b
//B - Frog 2 
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
    ll N, K; cin>>N>>K;
    vector<ll> hn(N+1,0);
    FOR(i,1,N+1){
        cin>>hn.at(i);
    }
    vector<ll> ans(N+1,INT64_MAX);
    ans[1]=0;
    auto get_val = [&](ll p,ll ofs)->ll{
        if(p-ofs<=0) return INT64_MAX;
        ll a=abs(hn[p]-hn[p-ofs]);
        return a+ans[p-ofs];
    };

    FOR(i,2,N+1){
        FOR(j,1,K+1){
            ll v=get_val(i,j);
            chmin(ans[i],v);
        }
    }
    cout<<ans[N]<<endl;
    return 0;
}