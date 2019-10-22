//https://atcoder.jp/contests/abc143/tasks/abc143_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
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
    ll N; cin>>N;
    vector<ll> dn(N);
    for(auto&& d:dn){
        cin>>d;
    }
    ll ans=0;    
    foreach_comb(N,2,[&](vector<ll>& a){
        ll x=a.at(0);
        ll y=a.at(1);
        ans += dn.at(x)*dn.at(y);
    });
    cout<<ans<<endl;

    return 0;
}