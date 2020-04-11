//https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d
//D - 薄氷渡り
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
//setコピーで間に合ったけど、flag立てと戻し、で訪問済を管理でよいみたい
int main() {
    ll m, n; cin>>m>>n; //x,y    
    vector<vector<ll>> mn(n,vector<ll>(m));
    for(auto&& ms:mn){
        for(auto&& x:ms){
            cin>>x;
        }
    }

    auto available = [&](ll x,ll y)->bool{
        if(x<0||x>=m) return false;
        if(y<0||y>=n) return false;
        return mn.at(y).at(x);
    };
    using pos = pair<ll,ll>;
    ll ans=0;
    function<void(ll,ll,set<pos>)> dfs = [&](ll x,ll y,set<pos> flag){
        if(not available(x,y)) return;
        if(flag.count({x,y})>0) return; //訪問済
        flag.insert({x,y});
        ans = max<ll>(ans, flag.size());
        //flag立て
        dfs(x+1,y,flag);
        dfs(x-1,y,flag);
        dfs(x,y+1,flag);
        dfs(x,y-1,flag);
        //flag戻し
    };

    FOR(y,0,n){
        FOR(x,0,m){
            set<pos> f;
            dfs(x,y,f);
        }
    }
    cout<<ans<<endl;

    return 0;
}