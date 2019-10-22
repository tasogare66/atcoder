//https://atcoder.jp/contests/atc001/tasks/dfs_a
//A - 深さ優先探索
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W; cin>>H>>W;
    vector<string> cwh(H);
    for(auto&& cw:cwh){
        cin>>cw;
    }

    auto getc = [&](ll x, ll y)->char&{
        return cwh.at(y).at(x);
    };
    function<void(ll,ll)> dfs = [&](ll x,ll y){
        if (x<0||x>=W) return;
        if (y<0||y>=H) return;
        auto& c = getc(x,y);
        if (c=='g') {
            cout<<"Yes"<<endl;
            exit(0);
        }
        if (c=='#') return;
        c='#'; //壁にする
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    };

    //s探す
    REP(y,H){
        REP(x,W){
            if (getc(x,y)=='s') {
                dfs(x,y);
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    return 0;
}