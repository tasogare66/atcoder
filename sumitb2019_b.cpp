//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b
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
    ll x=(double)N/1.08;
    ll x2=x+1;

    ll tmp=(double)x*1.08;
    ll tmp2=(double)x2*1.08;
    dump(tmp,tmp2);

    if(tmp==N){
        cout<<x<<endl;
    }else if(tmp2==N){
        cout<<x2<<endl;
    }else{
        cout<<":("<<endl;
    }
    return 0;
}