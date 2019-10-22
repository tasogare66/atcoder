//https://atcoder.jp/contests/abc038/tasks/abc038_d
//D - プレゼント
//入口は区間スケジューリング問題 -> longest_increasing_subsequence,同値のものはsortしておく
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

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
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<ll,ll>> whn(N);
    for(auto&& wh:whn){
        cin>>wh.first>>wh.second;
    }
    sort(whn.begin(),whn.end(),[](const auto& a,const auto& b){
         if(a.second==b.second) return a.first>b.first; //firstは降順にしておく
         return a.second<b.second; //second昇順
    });
    vector<ll> wn;
    for(const auto& wh:whn){
        wn.emplace_back(wh.first);
    }
    auto ans = longest_increasing_subsequence(wn, true);
    cout<<ans<<endl;
    return 0;
}