//https://atcoder.jp/contests/abc155/tasks/abc155_b
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
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }    
    bool ans=true;
    for(const auto& a:an){
        if(a%2==0){
            if(a%3==0 || a%5==0){

            }else{
                ans=false;
            }
        }
    }
    cout<<(ans?"APPROVED":"DENIED")<<endl;
    return 0;
}