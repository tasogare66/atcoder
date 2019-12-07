//https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_b
//B - チップ・ストーリー　～漆黒編～
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    ll ans=0;
    if (N%2==0){
        ll nd2=N/2;
        ll num=0;
        FOR(i,1,nd2){
            num+=i;
        }
        ans=num*4;
    }else{
        ll nd2=N/2;
        ll num=0;
        FOR(i,1,nd2){
            num+=i;
        }
        ans=num*4+1;
    }
    cout<<ans<<endl;
    return 0;
}