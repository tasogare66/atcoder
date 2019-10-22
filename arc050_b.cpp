//https://atcoder.jp/contests/arc050/tasks/arc050_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll R,B; cin>>R>>B;
    ll x,y; cin>>x>>y;

    auto check_func = [&](ll sum){ //花束の数をsum,この束の数が作れるかの判定関数
        ll a=(R-sum)/(x-1);
        ll b=(B-sum)/(y-1);
        if (R-sum < 0||B-sum<0) return false;
        if (a+b>=sum) return true;
        return false;
    };
    ll lb=0,ub=1e18+10;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(check_func(mid)){
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout<<lb<<endl;
    return 0;
}