//https://atcoder.jp/contests/tdpc/tasks/tdpc_target
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
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    struct Info{
        ll minx;
        ll maxx;
    };
    vector<pair<ll,ll>> xrn(N); //x,r
    vector<Info> infos(N);
    REP(i,N){
        auto&& p=xrn.at(i);
        cin>>p.first>>p.second;
        infos.at(i).minx = p.first - p.second;
        infos.at(i).maxx = p.first + p.second;
    }
    sort(infos.begin(),infos.end(),[](const auto& a,const auto& b){
        if(a.minx==b.minx) return (a.maxx<b.maxx);
        return a.minx<b.minx;
    });
    vector<ll> tmp;
    for(const auto& i:infos){
        tmp.emplace_back(i.maxx);
    }
    reverse(tmp.begin(),tmp.end());

    auto ans = longest_increasing_subsequence(tmp,true);
    cout<<ans<<endl;
    return 0;
}