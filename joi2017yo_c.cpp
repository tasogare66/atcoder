//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M,D; cin>>N>>M>>D; 
    vector<string> mn(N);
    for(auto&& m:mn){
        cin>>m;
    }
    auto check_row = [&](ll y,ll x){
        REP(p,D){
            if (y>=N||p+x>=M) return false;
            if (mn.at(y).at(p+x)=='#'){
                return false;
            }
        }
        return true;
    };
    auto check_col = [&](ll y,ll x){
        REP(p,D){
            if (p+y>=N||x>=M) return false;
            if (mn.at(p+y).at(x)=='#'){
                return false;
            }
        }
        return true;
    };
    ll ans=0;
    REP(y,N){
        REP(x,M){
            if (check_row(y,x)) ++ans;
            if (check_col(y,x)) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}