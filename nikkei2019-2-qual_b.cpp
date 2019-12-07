//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
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
ll MOD=998244353;
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> dn(N);
    for(auto&& d:dn){
        cin>>d;        
    }
    ll ans=1;
    if(dn.at(0)!=0)ans=0;
    sort(dn.begin(),dn.end());
    if(dn.at(0)==0&&dn.at(1)==1){
    } else {
        ans=0;
    }
    ll dist_num=1;
    ll prev_dist_num=1;
    FOR(i,1,dn.size()){
        ll d=dn.at(i);
        ll pd=dn.at(i-1);
        if(d!=pd){
            if (d-pd!=1) ans=0;
            prev_dist_num=dist_num;
            dist_num=0;
        }
		++dist_num;
		ans *= prev_dist_num;
		ans %= MOD;
	}
	cout<<ans<<endl;
    return 0;
}