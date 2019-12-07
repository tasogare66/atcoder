//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_b
//B - Exchange
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
    ll A,B,K; cin>>A>>B>>K;    
    auto exec_func = [](ll& my,ll& op){
        if(my%2==1) {
            my=max(my-1,0LL);
        }
        ll d=my/2;
        my=max(my-d,0LL);
        op+=d;
    };
    REP(i,K){
        if(i%2==0) exec_func(A,B);
        else exec_func(B,A);
    }
    cout<<A<<" "<<B<<endl;
    return 0;
}