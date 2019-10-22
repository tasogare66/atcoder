//https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_d
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
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M; //n両
    vector<ll> xm(M);
    for(auto&& x:xm){ //sort済
        cin>>x;
    }
    // vector<ll> rxm=xm; //反転させる
    // reverse(rxm.begin(),rxm.end());
    // for(auto&& x:rxm){
    //     x=N-x+1;
    // }

    auto check_base_func = [N](vector<ll>& _xm,ll min){
        ll okp=0;
        for(const auto& x:_xm){ //左へ
            ll dist=max(x-okp-1LL,0LL);
            if (dist>min) return false; //とどかない
            ll nex0=max(x,x+min-dist*2);
            ll nex1=x+(min-dist)/2;
            okp=max(nex0,nex1);
        }
        //dump(okp,M);
        return (okp>=N);
    };
    auto check_func = [&](ll min){
        //return check_base_func(xm,min) | check_base_func(rxm,min);
        return check_base_func(xm,min);
    };
#if LOCAL    
    //test
    cout<<check_base_func(xm,7)<<endl;
    // cout<<check_base_func(xm,3)<<endl;
    // cout<<check_base_func(xm,2)<<endl;
#endif

    ll lb=-1,ub=2*N;
    while(ub-lb>1){
        ll mid=(lb+ub)/2;
        if (check_func(mid)) {
            ub=mid;
        }else{
            lb=mid;
        }
        dump(lb,ub,mid);
    }
    cout<<ub<<endl;
    return 0;
}