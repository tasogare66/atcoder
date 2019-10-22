//https://atcoder.jp/contests/arc031/tasks/arc031_2
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
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll W=10,H=10;
    vector<string> ahw(H);
    ll onum=0;
    for(auto&& ah:ahw){
        cin>>ah;
        for(auto c:ah){
            if(c=='o') ++onum;
        }
    }

    vector<vector<ll>> matrix(H,vector<ll>(W,-1));
    auto getc = [&](ll x, ll y){
        return ahw.at(y).at(x);
    };
    auto mat = [&](ll x, ll y)->ll&{
        return matrix.at(y).at(x);
    };
    function<ll(ll,ll,ll)> dfs= [&](ll x,ll y,ll no)->ll{
        ll count=0;
        if (x<0||x>=W) return 0;
        if (y<0||y>=H) return 0;
        if (getc(x,y)=='x') return 0;
        auto& m = mat(x,y);
        if (m == no) return 0; //訪問済
        m=no; //訪問済を設定
        ++count;
        count += dfs(x+1,y,no);
        count += dfs(x-1,y,no);
        count += dfs(x,y+1,no);
        count += dfs(x,y-1,no);
        return count;
    };
    auto dfs_st = [&](ll x,ll y,ll no){
        ll count=0;
        count += dfs(x+1,y,no);
        count += dfs(x-1,y,no);
        count += dfs(x,y+1,no);
        count += dfs(x,y-1,no);
        return count;
    };

    ll tmp=dfs_st(1,0,10000);
    dump(tmp);

    REP(y,H){
        REP(x,W){
            if (getc(x,y)=='x'){
                ll count = dfs_st(x,y,y*W+x);
                if (count == onum) {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}