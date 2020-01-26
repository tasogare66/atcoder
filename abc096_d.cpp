//https://atcoder.jp/contests/abc096/tasks/abc096_d
//D - Five, Five Everywhere
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

auto Eratosthenes(const int n)
{
    vector<ll> result;
    vector<bool> is_prime(n+1,true); //trueで初期化
    for(ll i = 2; i <= n; ++i){
        if (is_prime.at(i)) {
            for(ll j = 2 * i; j <= n; j += i){
                is_prime[ j ] = false;
            }
            result.emplace_back( i );
        }
    }
    return result;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    auto prime_tbl = Eratosthenes(55555);
    //4n+1
    vector<ll> ans;
    for(const auto& p:prime_tbl){
        if(p%5==1){ //5で割って1余る素数
            ans.push_back(p);
            if(ans.size()>=N) break;
        }
    }
    FOR(i,0,ans.size()){
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}