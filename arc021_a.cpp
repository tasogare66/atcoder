//https://atcoder.jp/contests/arc021/tasks/arc021_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<vector<ll>> a44(4,vector<ll>(4));
    for(auto&& a4:a44){
        for(auto&& a:a4){
            cin>>a;
        }
    }
    bool ans=false;
    for (ll y=0;y<4;++y){
        for(ll x=1;x<4;++x){
            if(a44[y][x-1]==a44[y][x]) ans=true;
        }
    }
    for (ll x=0;x<4;++x){
        for(ll y=1;y<4;++y){
            if(a44[y-1][x]==a44[y][x]) ans=true;
        }
    }
    cout<<(ans?"CONTINUE":"GAMEOVER")<<endl;
    return 0;
}