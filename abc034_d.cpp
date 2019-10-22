//https://atcoder.jp/contests/abc034/tasks/abc034_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
struct Info{
    ll iw=0;
    ll ip=0;
    double sio=0;
    void calc(){
        sio=(double)iw*(double)ip/100.0;
    }
    double tmp=0;
    void setup(double con){
        tmp=sio-(double)(iw)*con;
    }
};
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    vector<Info> wpn(N);
    for(auto&& wp:wpn){
        cin>>wp.iw>>wp.ip;
        wp.calc();
    }

    auto check_func = [&](double con){ //濃度いける?
        for(auto&& wp:wpn){
            wp.setup(con);
        }
        sort(wpn.begin(),wpn.end(),[](const auto& a,const auto& b){ return a.tmp>b.tmp;}); //降順に
        //Kえらぶ
        double j=0;
        REP(i,K){
            j += wpn.at(i).tmp;
        }
        return (j>=0.0);
    };
    //check_func(0.225);

    double lb=0.0, ub=1.0;
    while(ub>lb&&!(abs(ub-lb)<1e-8)){
        auto mid=(lb+ub)/2;
        //double dmid=(double)mid/100.0;
        if (check_func(mid)){
            dump(lb,ub,mid,"true");
            lb=mid;
        }else {
            dump(lb,ub,mid,"false");
            ub=mid;
        }
    }
    cout<<fixed<<std::setprecision(10)<<lb*100<<endl;
    return 0;
}
