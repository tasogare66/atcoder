//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_c
//C - ロシアの旗 (Russian Flag)
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

void recursive_comb(vector<ll>& indexes, ll s, ll rest, std::function<void(vector<ll>&)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes.at(rest - 1) = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}
// nCkの組み合わせに対して処理を実行する
void foreach_comb(ll n, ll k, std::function<void(vector<ll>&)> f) {
    vector<ll> indexes(k);
    recursive_comb(indexes, n - 1, k, f);
}
//foreach_comb(N-1, 2, [&](vector<ll>& indexes) {
//    dump(indexes[0],indexes[1]);
//}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    vector<string> mn(N);
    for(auto&& m:mn){
        cin>>m;
    }

    ll ans=INT64_MAX;
    foreach_comb(N-1, 2, [&](vector<ll>& indexes) {
        dump(indexes[0],indexes[1]);
        //w,b,r
        auto check_str = [&](ll l){
            if (l<=indexes[0]) {
                return 'W';
            }else if(l<=indexes[1]){
                return 'B';
            }
            return 'R';
        };

        ll count=0;
        FOR(i,0,N){
            auto c=check_str(i);
            for(const auto& mc:mn.at(i)){
                if(mc != c){
                    ++count;
                }
            }
        }
        ans = min(ans,count);
    });
    cout<<ans<<endl;

    return 0;
}