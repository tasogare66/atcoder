//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
//重み付きUnion Find木
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#include "../weighted_union_find.cpp"

int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n,q; cin>>n>>q;
    wuf_tree<ll> wuft(n);
    REP(i,q){
        ll a; cin>>a;
        if(a==0){
            ll x,y,z; cin>>x>>y>>z;
            wuft.unite(x,y,z);
        }else{
            ll x,y; cin>>x>>y;
            if(wuft.is_same(x,y)){
                cout<<wuft.diff(x,y)<<endl;
            }else{
                cout<<"?"<<endl;
            }
        }
    }
    return 0;
}