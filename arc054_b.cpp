//https://atcoder.jp/contests/arc054/tasks/arc054_b
//B - ムーアの法則
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

double func_y(double P, double x){
    return x+P/pow(2,x/1.5);
}

//3分探索
int main() {
    double P; cin>>P;

    ll cnt=1000; //適当な回数やる
    double lb=0, ub=1e+18+1;
    while(cnt-->0){
        double l = (lb*2.0+ub)/3.0;
        double r = (lb+ub*2.0)/3.0;
        if (func_y(P,l)>func_y(P,r)) lb=l;
        else ub=r;
    }

    cout<<fixed<<std::setprecision(10)<<func_y(P,lb)<<endl;;
}

//微分して,2分探索
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    double P; cin>>P;
    double lb=0.0,ub=1e+18+1;

    //微分
    auto dxdy = [P](double x){
        double r=1-P/1.5*log(2)*pow(2,-x/1.5); //1-P*log2 / 1.5 * 2 ^ (-x/1.5)
        return r;
    };

    while(ub-lb>1e-9){
        auto mid=(ub+lb)/2.0;
        auto dy = dxdy(mid);
        if (dy < 0){
            lb=mid;
        }else {
            ub=mid;
        }
        dump(lb,ub,dy);
    }    

    double ans=func_y(P,lb);
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}