//https://atcoder.jp/contests/arc004/tasks/arc004_2
//B - 2点間距離の最大と最小 ( Maximum and Minimum )
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
    std::ifstream in("./test/sample-4.in");
    //std::ifstream in("./input.txt");
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
    ll ans_max=std::accumulate(dn.begin(),dn.end(),0LL); //これは合計
    ll ans_min=INT32_MAX;
    if(N==1){
        ans_min=dn.at(0);
    } else if(N==2){
        ans_min=abs(dn.at(0)-dn.at(1));
    }else{
        ll longest=0;
        ll sum_v=0;
        FOR(i,0,N){
            sum_v += dn.at(i);
            chmax(longest, dn.at(i));
        }
        if (sum_v>longest*2) {
            ans_min=0;
        }else{
            ans_min=longest-(sum_v-longest);
        }
    }
    cout<<ans_max<<endl;
    cout<<ans_min<<endl;    
    return 0;
}