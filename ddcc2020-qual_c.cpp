//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c
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
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W,K; cin>>H>>W>>K;
    vector<string> swh(H);
    for(auto&& sw:swh){
        cin>>sw;
    }

    vector<vector<ll>> ans(H,vector<ll>(W,0));
    ll no=1;
    REP(y,swh.size()){
        auto& s=swh.at(y);
        REP(x,W){
            if(s.at(x)=='#'){
                ans[y][x]=no;
                ++no;
            }
        }
    }
    //右にのばす
    REP(y,H){
        REP(x,W){
            if(ans[y][x]==0&&x-1>=0){
                ans[y][x]=ans[y][x-1];
            }
        }
    }
    //左にのばす
    REP(y,H){
        for(ll x=W-1;x>=0;--x){
            if(ans[y][x]==0&&x+1<W){
                ans[y][x]=ans[y][x+1];
            }
        }
    }
    //下にのばす
    REP(y,H){
        REP(x,W){
            if(ans[y][x]==0&&y-1>=0){
                ans[y][x]=ans[y-1][x];
            }
        }
    }
    //上にのばす
    for(ll y=H-1;y>=0;--y){
        REP(x,W){
            if(ans[y][x]==0&&y+1<H){
                ans[y][x]=ans[y+1][x];
            }
        }
    }

    for(auto&& ah:ans){
        REP(x,ah.size()){
            if(x!=0)cout<<" ";
            cout<<ah.at(x);
        }
        cout<<endl;
    }

    return 0;
}