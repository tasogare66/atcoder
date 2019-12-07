//https://atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_c
//C - ロト2
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
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    unordered_map<ll,ll> tbl;
    for(auto&& a:an){
        cin>>a;
        tbl[__gcd(a,K)]++;
    }
    ll ans=0;
    for(const auto& r0:tbl){
        for(const auto& r1:tbl){
            if (r0.first*r1.first%K==0){
                if(r0.first<r1.first){
                    ans += r0.second*r1.second;
                }else if(r0.first==r1.first){
                    ans += r0.second*(r0.second-1)/2;
                }
            }
        }
    }
    cout<<ans<<endl;
}
#if 0
int main() {
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll ans=0;
    REP(i,N){
        FOR(j,i+1,N){
            if(an[i]*an[j]%K==0){
                ++ans;
            }
        }
    }
    cout<<ans<<endl;    
    return 0;
}
#endif