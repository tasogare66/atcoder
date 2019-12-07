//https://atcoder.jp/contests/abc144/tasks/abc144_e
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
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    vector<ll> an(N),fn(N);
    for(auto&& a:an){
        cin>>a;
    }
    for(auto&& f:fn){
        cin>>f;
    }
    sort(an.begin(),an.end(),greater<ll>());
    sort(fn.begin(),fn.end());

    auto check_t = [&](ll v, ll k){
        REP(i,N){
            ll tmp=an.at(i)*fn.at(i)-v;
            if (tmp>0) {
                ll a=(tmp+fn.at(i)-1)/fn.at(i);
                k-=a;
                if(k<0)return false;
            }
        }
        return true;
    };
    dump(check_t(11,K));
    dump(check_t(12,K));

    ll lb=-1,ub=1e13;//INT64_MAX/2;//(1e10*1e6+1e11)*2;
    while(ub-lb>1) {
        ll mid = (lb+ub)/2;
        if (check_t(mid,K)){
            ub=mid;
        }else {
            lb=mid;
        }
        dump(mid,lb,ub);
    }
    cout<<ub<<endl;

    return 0;
}