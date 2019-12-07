//https://atcoder.jp/contests/abc145/tasks/abc145_c
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
    vector<double> x(N+1);
    vector<double> y(N+1);
    FOR(i,1,N+1){
        cin>>x.at(i)>>y.at(i);
    }

    double total=0;
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);  
    do {
        dump(v);
        //double len=0;
        FOR(i,1,v.size()){
            ll s=v.at(i);
            ll e=v.at(i-1);
            dump(s,e);
            auto dx=x.at(s)-x.at(e);
            auto dy= y.at(s)-y.at(e);
            total += sqrt(dx*dx+dy*dy);
        }
    } while( next_permutation(v.begin(), v.end()) );
    double ans=total;
    FOR(i,1,N+1){
        ans /= (double)(i);
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}