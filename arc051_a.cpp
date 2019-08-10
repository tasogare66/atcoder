//https://atcoder.jp/contests/arc051/tasks/arc051_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using vec=pair<ll,ll>;
int main() {
    ll x1, y1, r; cin>>x1>>y1>>r;
    ll x2, y2, x3, y3; cin>>x2>>y2>>x3>>y3;
    bool red=true;
    //円が矩形の内側か
	if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3){
        red=false;
    }
    //矩形が円の内側か
    array<vec,4> vtbl = {
        {{x2,y2},{x3,y3},{x2,y3},{x3,y2}},
    };
    bool blue=false;
    for(auto& v:vtbl){
        ll x=v.first-x1;
        ll y=v.second-y1;
        double len=sqrt(x*x+y*y);
        if(len>r) {
            blue=true;
            break;
        }
    }
    cout<<(red?"YES":"NO")<<endl;
    cout<<(blue?"YES":"NO")<<endl;
	return 0;
}