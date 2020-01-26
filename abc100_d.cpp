//https://atcoder.jp/contests/abc100/tasks/abc100_d
//D - Patisserie ABC
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
    ll N,M; cin>>N>>M;
    struct Data{
        Data()=default;
		Data(ll ix, ll iy, ll iz) : val{ix,iy,iz} {}
		std::array<ll,3> val;
        std::array<ll,3> work;
        ll sum() const {
            return (work[0]+work[1]+work[2]);
        }
	};
    vector<Data> xyzn;
    FOR(i,0,N){
        ll x,y,z; cin>>x>>y>>z;
        xyzn.emplace_back(x,y,z);
    }
    ll mask_max=1<<3;
    ll ans=0;
    FOR(mask,0,mask_max){
        ll flag[3]={};
        FOR(i,0,3){
            flag[i] = (mask&(1LL<<i))?-1:1;
        }
        for(auto&& d:xyzn){
            FOR(i,0,3){
                d.work[i] = d.val[i]*flag[i];
            }
        }
        sort(xyzn.begin(),xyzn.end(), [](const auto& a,const auto& b){ return a.sum()>b.sum(); });
        ll sumv=0;
        FOR(i,0,M){
            sumv += xyzn.at(i).sum();
        }
        ans = max(ans,sumv);
    }
    cout<<ans<<endl;
    return 0;
}