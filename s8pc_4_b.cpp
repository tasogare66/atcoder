//https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
//B - Buildings are Colorful!
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

void recursive_comb(vector<ll>& indexes, ll s, ll rest, std::function<void(vector<ll>&)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes.at(rest - 1) = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}
// nCkの組み合わせに対して処理を実行する
void foreach_comb(ll n, ll k, std::function<void(vector<ll>&)> f) {
    vector<ll> indexes(k);
    recursive_comb(indexes, n - 1, k, f);
}
//foreach_comb(N-1, 2, [&](vector<ll>& indexes) {
//    dump(indexes[0],indexes[1]);
//});

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an) {cin>>a;}

    auto calc_cost = [N](const vector<ll>& mvd,vector<ll> ann)->ll{
        ll ret=0;
        ll maxh=ann.at(0);
        FOR(i,0,N){
            auto it = find(mvd.begin(),mvd.end(), i);
            if(i!=0 && it != mvd.end()){
                auto&& a=ann.at(i);
                if(maxh<a){
                } else {
                    ll add=maxh-a+1;
                    ret += add;
                    a += add;
                }
            }
            maxh=max(ann.at(i),maxh);
        }
        return ret;
    };

    //どれが見える状態になるかcombinationで選んで、それのcostを全探索
    ll ans=INT64_MAX;
    foreach_comb(N,K,[&](vector<ll>& indexes) {
        dump(indexes);
        ans = min(ans,calc_cost(indexes,an));
    });
    cout<<ans<<endl;

    return 0;
}

struct Info{
    ll cost=0;
    ll h=0;
    ll pos=0;
};

int main__() {
    ll N,K; cin>>N>>K;    
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }

    ll maxh=an.at(0);
    vector<Info> tbl(N);
    FOR(i,0,N){
        auto&& d=tbl.at(i);
        d.h=an.at(i);
        d.cost = max(maxh-d.h,0LL);
        d.pos=i;
        maxh = max(maxh,an.at(i));
    }

    //cost優先、同costは後ろ優先
    sort(tbl.begin(),tbl.end(),[](const auto& a, const auto& b){ 
        if(a.cost==b.cost) return a.pos>b.pos;
        return a.cost<b.cost;
    });

    //動かすやつ決める
    vector<ll> mvd;
    FOR(i,0,K){
        mvd.push_back(tbl.at(i).pos);
    }

    ll ans=0;
    maxh=an.at(0);
    FOR(i,0,N){
        auto it = find(mvd.begin(),mvd.end(), i);
        if(i!=0 && it != mvd.end()){
            auto&& a=an.at(i);
            if(maxh<a){
            } else {
                ll add=maxh-an.at(i)+1;
                a += add;
                ans += add;
            }
        }
        maxh=max(an.at(i),maxh);
    }
    cout<<ans<<endl;

    return 0;
}