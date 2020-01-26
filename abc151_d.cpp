//https://atcoder.jp/contests/abc151/tasks/abc151_d
//D - Maze Master
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
using Mat = vector<vector<ll>>;
int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-1.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    int H,W; cin>>H>>W;
    vector<string> shw(H);
    for(auto&& sh:shw){
        cin>>sh;
    }

    pair<int,int> ofs_tbl[] = {
        { 1, 0 }, { -1, 0},
        { 0, -1}, { 0, 1},
    };
    auto getid = [&](int y, int x){
        if(y<0||y>=H) return -1;
        if(x<0||x>=W) return -1;
        return y*W+x;
    };
    auto getch = [&](int y, int x)->char{
        return shw.at(y).at(x);
    };
    int num=H*W;
    Mat mat(num, vector<ll>(num,INT32_MAX));
    FOR(y,0,H){
        FOR(x,0,W){
            auto f = getid(y,x);
            mat[f][f]=0; //同じところ0いれないと...
            if(f<0) continue;
            if(getch(y,x)=='#') continue;
            for(const auto& ofs:ofs_tbl){
                auto ey = y+ ofs.first;
                auto ex = x + ofs.second;
                auto t = getid(ey, ex);
                if (t<0) continue;
                if(getch(ey,ex)=='#') continue;
                mat[f][t]=1;
                mat[t][f]=1;
            }
        }
    }

    auto warshall_floyd = [&](int n) //nは頂点数
    {
	    for(int i = 0; i < n; i++) // 経由する頂点
		    for(int j = 0; j < n; j++) // 開始頂点
			    for(int k = 0; k < n; k++) // 終端
				    mat[j][k] = std::min(mat[j][k], mat[j][i] + mat[i][k]);
    };
	warshall_floyd(num); //O(n^3)

    ll ans=0;
    REP(i,num){
        REP(j,num){
            if(mat[i][j]>=INT32_MAX) continue;
            ans = max(ans, mat[i][j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}