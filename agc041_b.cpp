//https://atcoder.jp/contests/agc041/tasks/agc041_b
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
    //std::ifstream in("./test/sample-3.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif    
    ll N,M,V,P; cin>>N>>M>>V>>P;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end(),greater<ll>());
    dump(an);

    auto check_func = [&](ll cur)->bool{
        ll P0 = P-1;
        if(cur<=P0) return true;
        ll ppoint=an[cur]+M;
        if (ppoint < an[P0]) return false;
        ll rest = M*V-M*P;
        for(ll i=an.size()-1;i>=P0;--i){
            if (i==cur) continue;
            auto subv = min(M,max(ppoint-an[i],0LL));
            //dump(i,subv);
            rest -= subv;
        }
        if (rest <= 0) return true;
        return false; //trueだと採用
    };
    REP(i,10){
        dump(i, check_func(i));
    }

    ll lb=0,ub=an.size();
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        auto ck = check_func(mid);
        if (ck){
            lb=mid;
        }else{
            ub=mid;
        }
        dump(mid,ck,lb,ub);
    }
    cout<<lb+1<<endl;
    return 0;
}