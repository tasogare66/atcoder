//https://atcoder.jp/contests/abc006/tasks/abc006_4
//D - トランプ挿入ソート
//longest_increasing_subsequence
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    vector<ll> cn(N);
    for(auto&& c:cn){
        cin>>c;
    }
    ll ans=longest_increasing_subsequence(cn,true);
    cout<<cn.size()-ans<<endl;
    return 0;
}