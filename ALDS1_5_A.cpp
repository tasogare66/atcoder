//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
//ALDS1_5_A
//Exhaustive Search
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
int main(){
    ll n; cin>>n;
    vector<ll> an(n);
    for(auto&& a:an){
        cin>>a;
    }
    ll q; cin>>q;
    vector<ll> mq(q);
    for(auto&& m:mq){
        cin>>m;
    }

    function<ll(ll,ll)> solve = [&](ll i,ll m)->bool{
        if (m==0)return true;
        if(i>=n) return false;
        return solve(i+1,m) | solve(i+1, m-an.at(i));
    };

    for(const auto& m:mq){
        cout<<(solve(0,m)?"yes":"no")<<endl;
    }
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n; cin>>n;
    vector<ll> an(n);
    for(auto&& a:an){
        cin>>a;
    }
    ll q; cin>>q;
    vector<ll> mq(q);
    for(auto&& m:mq){
        cin>>m;
    }

    auto solve = [&](ll m)->bool{
        ll max=1LL<<n;
        FOR(i,0,max){
            ll v=0;
            FOR(j,0,n){
                if(i&(1LL<<j)) v+=an.at(j);
            }
            dump(i,v);
            if(v==m) return true;
        }
        return false;
    };

    for(const auto& m:mq){
        cout<<(solve(m)?"yes":"no")<<endl;
    }
    return 0;
}