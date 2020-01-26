//https://atcoder.jp/contests/arc035/tasks/arc035_b
//B - アットコーダー王国のコンテスト事情
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
constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> tn(N);
    for(auto&& t:tn){
        cin>>t;
    }
    sort(tn.begin(),tn.end());
    ll sum=0;
    ll pena = 0;
    ll count = 1;
    ll prev = -1;
    ll num = 1;
    auto flush_num = [&](){
        FOR(i,1,num+1){
            count *= i;
            count %= MOD;
        }
        num=1;
    };
    for(const auto& t:tn){
        pena += (sum + t);
        //pena %= MOD;
        sum += t;
        //sum %= MOD;
        if (prev == t) {
            ++num;
        }else{
            flush_num();
        }
        prev = t;
    }
    flush_num();

    cout<<pena<<endl;
    cout<<count<<endl;
    return 0;
}