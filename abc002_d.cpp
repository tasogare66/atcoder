//https://atcoder.jp/contests/abc002/tasks/abc002_4
//D - 派閥
//bitフラグで関係が存在するか全探索
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

//dfsこっちのがはやい
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, M; cin>>N>>M;
    vector<pair<ll,ll>> xym(M);
    vector<map<ll,ll>> pair_map(N);
    for(auto&& p:xym){
        ll x,y; cin>>x>>y; --x,--y;
        if(x>y) swap(x,y);
        p.first=x;
        p.second=y;
        pair_map.at(p.first)[p.second]=1;
        pair_map.at(p.second)[p.first]=1;
    }

    function<ll(ll,ll)> search = [&](ll n, ll mask)->ll{
        if(n>=N) {
            dump(mask);
            return __builtin_popcountll(mask);
        }
        //n入る?
        bool flag=true;
        FOR(i,0,N){
            if(mask&(1LL<<i)) {
                if(pair_map.at(n).count(i)<=0){
                    flag=false;
                    break;
                }
            }
        }
        ll ret = search(n+1,mask);
        if(flag){
            ret = max(ret,search(n+1,mask|1LL<<n));
        }

        return ret;
    };

    cout<<search(0,0)<<endl;

    return 0;
}

struct Info{
    ll x,y;
    ll flag;
	Info(ll ix, ll iy) : x(ix), y(iy), flag(1 << ix | 1 << iy) {}
};
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    vector<Info> xym;
    REP(i,M){
        ll x,y; cin>>x>>y;
        xym.emplace_back(x-1,y-1);
    }
 
    ll ans=1;
    for(ll msk=1;msk<(1<<N);++msk){
        ll count=0;
        for(const auto& xy:xym){
            if (xy.flag == (xy.flag&msk)) ++count;
        }
        ll num_bit=0;
        REP(i,N){
            if(msk&(1<<i))++num_bit;
        }
        ll check_count=num_bit*(num_bit-1)/2;
        if(check_count==count){
            ans=max(ans,num_bit);
        }
    }
    cout<<ans<<endl;
 
    return 0;
}