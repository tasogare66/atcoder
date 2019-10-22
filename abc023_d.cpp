//https://atcoder.jp/contests/abc023/tasks/abc023_d
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
    //std::ifstream in("./test/sample-1.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<ll,ll>> hsn(N); //h,s
    for(auto&& hs:hsn){
        cin>>hs.first>>hs.second;
    }
    auto check_t = [&](ll v){
        //map<ll,ll> tbl;
        vector<ll> vec;
        for(auto&& hs:hsn){
            ll h=hs.first;
            ll s=hs.second;
            ll t=(v-h)/s;
            if(v-h<0)return false;
            //tbl[t]++;
            //if(tbl[t]>t+1) return false;
            vec.emplace_back(t);
        }
        //ll trm=tbl.crbegin()->first;
        //ll sum=0;
        //for(const auto&it :tbl){
        //    if(it.second>it.first+1-sum) return false;
        //    sum += it.second;
        //}
        sort(vec.begin(),vec.end());
        FOR(i,0,N){
            if(vec.at(i)<i)return false;
        }
        return true;
    };
    auto c=check_t(9);
    dump(c);

    ll lb=0,ub=INT64_MAX/2;//(1e10*1e6+1e11)*2;
    while(ub-lb>1)
    {
        ll mid = (lb+ub)/2;
        if (check_t(mid)){
            ub=mid;
        }else {
            lb=mid;
        }
        dump(mid,lb,ub);
    }
    cout<<ub<<endl;
    return 0;
}
