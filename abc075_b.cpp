//AtCoder ABC075 B - Minesweeper
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
using Mat=vector<vector<ll>>;
int main() {
    ll H,W;
    cin>>H>>W;
    vector<string> mt(H);
    for(auto& m:mt){
        cin>>m;
    }
    auto check_bom = [&](ll x,ll y){
        if (x<0||x>=W) return 0;
        if (y<0||y>=H) return 0;
        if (mt[y][x]=='#') return 1;
        return 0;
    };
    Mat ans(H,vector<ll>(W,0));
    for(ll y=0;y<H;++y){
        for(ll x=0;x<W;++x){
            if (!check_bom(x,y)) {
                ans[y][x] += check_bom(x-1,y-1);
                ans[y][x] += check_bom(x,y-1);
                ans[y][x] += check_bom(x+1,y-1);
				ans[y][x] += check_bom(x-1, y);
				ans[y][x] += check_bom(x+1, y);
				ans[y][x] += check_bom(x-1, y+1);
				ans[y][x] += check_bom(x, y+1);
				ans[y][x] += check_bom(x+1, y+1);
            } else {
                ans[y][x] = -1;
            }
        }
    }
    for(auto&& yt:ans){
        for(auto && x: yt){
            cout<<(char)(x>=0?('0'+x):'#');
        }
        cout<<endl;
    }
    return 0;
}