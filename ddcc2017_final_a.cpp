//https://atcoder.jp/contests/ddcc2017-final/tasks/ddcc2017_final_a
//A - 正方形のチップ２
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
    ll K; cin>>K;

    auto check_inner = [&](double px,double py,double cx, double cy, double r){
        auto x=(cx-px);
        auto y=(cy-py);
        double d=r*r-(x*x+y*y);
        return (d>=-DBL_EPSILON);
    };
    auto count_func= [&](ll r2){
        ll ret=0;
        ll num=r2/K;
        double u=K;//(double)r2/(double)K;
        double r=(double)r2/2.0;
        for(ll y=0;y<num;++y){
            for(ll x=0;x<num;++x){
                double dx=x*u;
                double dy=y*u;
                if (check_inner(dx,dy,r,r,r) &&
                check_inner(dx+u,dy,r,r,r) &&
                check_inner(dx,dy+u,r,r,r) &&
                check_inner(dx+u,dy+u,r,r,r)){
                    dump(x,y);
                    ++ret;
                }
            }
        }
        return ret;
    };

    ll ans0 = count_func(200);
    ll ans1 = count_func(300);
    cout<<ans0<<" "<<ans1<<endl;
    return 0;
}