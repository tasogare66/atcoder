//https://atcoder.jp/contests/agc018/tasks/agc018_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());

    vector<ll> candidate;
    for(const auto& a:an){
        auto df=N-a;
        if(df>=0) candidate.push_back(df);
    }

    return 0;
}