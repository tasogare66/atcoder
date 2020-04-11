//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h
//H - LIS
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

template< typename T >
size_t longest_increasing_subsequence(const vector< T > &a, bool strict) {
    vector< T > lis;
    for(auto &p : a) {
        typename vector< T >::iterator it;
        if(strict) it = lower_bound(begin(lis), end(lis), p);
        else it = upper_bound(begin(lis), end(lis), p);
        //終端だと後ろに追加,そうでない場合、lower_boundの位置を更新
        if(end(lis) == it) lis.emplace_back(p);
        else *it = p;
    }
    return lis.size();
}

int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    auto ans=longest_increasing_subsequence(an, false);
    cout<<ans<<endl;
    return 0;
}