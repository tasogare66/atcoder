//https://atcoder.jp/contests/agc020/tasks/agc020_b
//B - Ice Rink Game
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
    ll K; cin>>K;
    vector<ll> ak(K);
    for(auto&& a:ak){
        cin>>a;
    }
    //反対から
    ll min=2,max=3;
    //assert(ak.back()==2);
    if(ak.back()!=2){
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=ak.size()-1;i>=0;--i){
        ll a=ak.at(i);
        ll lv = (min+a-1)/a;
        min = lv * a;
        ll rv = max / a;
        max = rv * a + a-1;
        if (min>max || min<=0|| max<=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<min<<" "<<max<<endl;
    return 0;
}