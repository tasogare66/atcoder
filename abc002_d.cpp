//https://atcoder.jp/contests/abc002/tasks/abc002_4
//D - 派閥
//bitフラグで関係が存在するか全探索
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info{
    ll x,y;
    ll flag;
	Info(ll ix, ll iy) : x(ix), y(iy), flag(1 << ix | 1 << iy) {}
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    vector<Info> xym;
    REP(i,M){
        ll x,y; cin>>x>>y;
        xym.emplace_back(x-1,y-1);
    }
 
    ll ans=1;
    for(ll msk=1;msk<(1<<N);++msk){
        ll count=0;
        for(const auto& xy:xym){
            if (xy.flag == (xy.flag&msk)) ++count;
        }
        ll num_bit=0;
        REP(i,N){
            if(msk&(1<<i))++num_bit;
        }
        ll check_count=num_bit*(num_bit-1)/2;
        if(check_count==count){
            ans=max(ans,num_bit);
        }
    }
    cout<<ans<<endl;
 
    return 0;
}