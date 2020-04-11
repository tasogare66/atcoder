//https://atcoder.jp/contests/abc154/tasks/abc154_d
//D - Dice in Line
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
    ll N,K; cin>>N>>K;
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }
    vector<double> expval(N+1,0);
    FOR(i,1,N+1){
        ll a=an.at(i);
        double ded = (1+a)*a/2;
        expval.at(i)=ded/(double)a;
    }
    vector<double> sums(N+1,0);
    double tmp=0.0;
    FOR(i,1,N+1){
        tmp += expval.at(i);
        sums.at(i)=tmp;
    }
    double ans=0;
    FOR(i,0,N+1-K){
        ans = max(ans, (sums.at(i+K) - sums.at(i)));
        dump(i+K,i);
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}