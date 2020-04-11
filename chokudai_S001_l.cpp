//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_l
//L - N回スワップ
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
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }
    ll count=0;
    FOR(i,1,N+1){
        while(an.at(i)!=i){
            auto a=an.at(i);
            swap(an.at(i), an.at(a));
            ++count;
        }
    }    
    bool ans=(N-count)%2==0;
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}