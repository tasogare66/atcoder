//https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_b
//B - コンテスト
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> ws(10);
    vector<ll> ks(10);
    for(auto&& w:ws){
        cin>>w;
    }
    for(auto&& k:ks){
        cin>>k;
    }
    sort(ws.begin(),ws.end(),greater<ll>());
    sort(ks.begin(),ks.end(),greater<ll>());
    ll ans_w=0;
    ll ans_k=0;
    REP(i,3){
        ans_w += ws.at(i);
        ans_k += ks.at(i);
    }
    cout<<ans_w<<" "<<ans_k<<endl;
    return 0;
}