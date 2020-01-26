//https://atcoder.jp/contests/past201912-open/tasks/past201912_d
//D - 重複検査 / Duplicated?
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
    unordered_map<int,int> tbl;
    FOR(i,1,N+1){
        tbl[i]=0;
    }
    FOR(i,1,N+1){
        ll a; cin>>a;
        tbl[a]++;
    }    
    ll from=-1;
    ll to=-1;
    FOR(i,1,N+1){
        if(tbl[i]==0) {
            assert(from==-1);
            from=i;
        } else if(tbl[i]==2){
            assert(to==-1);
            to=i;
        }
    }
    if(from==-1) cout<<"Correct"<<endl;
    else cout<<to<<" "<<from<<endl;
    return 0;
}