//https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_l
//L - 長方形 β
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

//strict=trueの場合、lower_bound(以上を更新するので,同じ値は含まれない)
//O(nlongn)
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
    vector<pair<ll,ll>> abn(N);
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        if (A<B) swap(A,B); //firstを大きくしとく 
        abn.at(i).first=A;
        abn.at(i).second=B;
    }

    //向きをそろえてsort
    //abc038_dと同じ
    sort(abn.begin(),abn.end(),[](const auto& a,const auto& b){
         if(a.second==b.second) return a.first>b.first; //firstは降順にしておく
         return a.second<b.second; //second昇順
    });
    vector<ll> wn;
    for(const auto& wh:abn){
        wn.emplace_back(wh.first);
    }
    auto ans = longest_increasing_subsequence(wn, true);
    cout<<ans<<endl;

    return 0;
}