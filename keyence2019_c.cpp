//https://atcoder.jp/contests/keyence2019/tasks/keyence2019_c
//C - Exam and Wizard
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
    vector<ll> bn(N);    
    for(auto&& a:an){
        cin>>a;
    }
    for(auto&& b:bn){
        cin>>b;
    }
    ll ans=0;
    ll sub=0;
    vector<ll> rn(N);
    REP(i,N){
        auto a=an.at(i);
        auto b=bn.at(i);
        if(a<b){
            ++ans;
            sub += (b-a);
        }else{
            rn.at(i)=a-b;
        }
    }
    sort(rn.begin(),rn.end(),greater<ll>());
    REP(i,N){
        if(sub>0){
            sub -= rn.at(i);
            ++ans;
        }
    }
    if (sub>0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}