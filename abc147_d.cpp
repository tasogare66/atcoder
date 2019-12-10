//https://atcoder.jp/contests/abc147/tasks/abc147_d
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
constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-3.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N;cin>>N;
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }    

    ll ans=0;
#if 1
    unordered_map<ll,ll> bitnum;
    FOR(i,1,N+1){
        ll a=an.at(i);
        ll cnt=0;
        while(a>0){
            if(a&(1)!=0) ++bitnum[cnt];
            a>>=1;
            ++cnt;
        }
    }
    for(const auto& b:bitnum){
        dump(b.first,b.second);
        ll k=b.second;
        ll tmp=k*(N-k);
        tmp%=MOD;
        ll sft=(1LL<<b.first)%MOD;
        ans += ((tmp*sft)%MOD);
        ans %= MOD;
    }
#if LOCAL&01
    ll ans2=0;
    FOR(i,1,N){
        FOR(j,i+1,N+1){
            dump(i,j,an[i],an[j],an[i]^an[j])
            ans2 += (an[i] ^ an[j]);
            ans2 %= MOD;
        }
    }
    dump(ans2);
#endif
#endif
    cout<<ans<<endl;

    return 0;
}