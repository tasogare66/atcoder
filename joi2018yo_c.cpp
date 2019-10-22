//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_c
//C - 幹線道路 (Trunk Road
//全探索でいいのか
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
template< typename T >
using Matrix = vector< vector< T > >;
int main() {
    ll H,W; cin>>H>>W;
    Matrix<ll> ahw(H+1,vector<ll>(W+1));
    FOR(y,1,H+1){
        FOR(x,1,W+1){
            cin>>ahw.at(y).at(x);
        }
    }

    auto check_func = [&](ll ly,ll lx){
        ll val=0;
        FOR(y,1,H+1){
            if(ly==y)continue;
            FOR(x,1,W+1){
                if(lx==x)continue;
                val += min(abs(ly-y),abs(lx-x)) * ahw.at(y).at(x);
            }
        }
        return val;
    };

    ll ans=INT64_MAX;
    FOR(ly,1,H+1){
        FOR(lx,1,W+1){
            ans = min(check_func(ly,lx),ans);
        }
    }
    cout<<ans<<endl;

    return 0;
}