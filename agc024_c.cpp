//https://atcoder.jp/contests/agc024/tasks/agc024_c
//C - Sequence Growing Easy
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
    for(auto&&a:an){
        cin>>a;
    }
    bool ans_flag=(an.at(0)==0);
    ll count=0;
    //貪欲,x(i)=x(i+1)+1 だと +1
    //x(i)<=x(i+1) だと +x(i+1)
    for(ll i=1;i<an.size();++i){
        if(an.at(i)>an.at(i-1)+1){
            ans_flag=false;
        }else if(an.at(i)==an.at(i-1)+1){
            count += 1;
        }else{
            count += an.at(i);
        }
    }
    if(not ans_flag) count=-1;
    cout<<count<<endl;
    return 0;
}