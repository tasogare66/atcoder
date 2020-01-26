//https://atcoder.jp/contests/abc153/tasks/abc153_e
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
    ll H,N; cin>>H>>N;
    struct Data{
        ll a,b;
    };
    vector<Data> abn;
    abn.reserve(N);
    REP(i,N){
        Data d;
        cin>>d.a>>d.b;
        abn.push_back(d);
    }

    vector<ll> hpb(H+1, INT32_MAX);
    hpb[H]=0;

    for(ll h=H;h>=0;--h){
        for(const auto& d:abn){
            auto nex_h=max(h-d.a,0LL);
            chmin(hpb[nex_h], hpb[h]+d.b);
        }
    }
    auto ans=hpb[0];
    cout<<ans<<endl;
    return 0;
}