//https://atcoder.jp/contests/abc143/tasks/abc143_d
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
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> ln(N);
    for(auto&& l:ln){
        cin>>l;
    }
    sort(ln.begin(),ln.end());
    ll ans=0;
    REP(i,N){
        ll a=ln.at(i);
        FOR(j,i+1,N){
            //if(i==j)continue;
            ll b=ln.at(j);
            auto it = lower_bound(ln.begin(),ln.end(),a+b);
            //if (it==ln.end()) continue;
            if (it==ln.begin()) continue;
            --it;
            auto d = std::distance(ln.begin(),it);
            ans += max<ll>(d - j,0);
        }
    }
    cout<<ans<<endl;
    return 0;
#if 0
    //TLE...
    ll ans=0;
    foreach_comb(N,3,[&](vector<ll>& t){
        //dump(t);
        ll a=ln.at(t.at(0));
        ll b=ln.at(t.at(1));        
        ll c=ln.at(t.at(2));        
        if(a<b+c&&b<c+a&&c<a+b){
            ++ans;
        }
    });
    cout<<ans<<endl;
#endif
    return 0;
}