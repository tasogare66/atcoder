//https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_c
//C - When I hit my pocket...
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
    ll K,A,B; cin>>K>>A>>B;
    ll ad=B-A;
    ll ans=1;
    if(ad>2 && K-(A-1)>0){
        ans+=(A-1);
        K-=(A-1);
        ll r0=K/2;
        ll r1=K-r0*2;
        ans+=r0*(B-A);
        ans+=r1;
    }else{
        ans+=K;
    }
    cout<<ans<<endl;
    return 0;
}