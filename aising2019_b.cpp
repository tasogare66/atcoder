//https://atcoder.jp/contests/aising2019/tasks/aising2019_b
//B - Contests
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
    ll A,B; cin>>A>>B;
    vector<ll> pn(N+1);
    unordered_map<ll,ll> tbl;
    tbl[0]=0;
    tbl[1]=0;
    tbl[2]=0;
    FOR(i,1,N+1){
        ll p; cin>>p;
        pn.at(i)=p;
        ll no=-1;
        if (p<=A){
            no=0;
        }else if(p>=A+1 && p <=B){
            no=1;
        }else if(p>=B+1){
            no=2;
        }else{
            assert(0);
        }
        tbl[no]++;
    }    
    ll ans=min(tbl[0],tbl[1]);
    ans=min(ans,tbl[2]);
    cout<<ans<<endl;
    return 0;
}