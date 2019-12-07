//https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_d
//D - 家の建設
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
template< typename T >
using Matrix = vector< vector< T > >;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H=125,W=125,K,V; cin>>H>>W>>K>>V;
    Matrix<ll> mat(H+1,vector<ll>(W+1,0));
    FOR(y,1,H+1)FOR(x,1,W+1){
        cin>>mat[y][x];
    }

    Matrix<ll> sumtbl(H+1,vector<ll>(W+1,0));
    FOR(y,1,H+1){
        ll sum=0;
        FOR(x,1,W+1){
            sum+=mat[y][x];
            sumtbl[y][x]=sum;
        }
    }

    auto calc_val=[&](ll px,ll py, ll ex, ll ey){
        ll ret=0;
#if 0
        FOR(y,py,ey+1){
            FOR(x,px,ex+1){
                ret += mat[y][x];
            }
        }
#else
        for(ll y=py;y<=ey;++y){
            ret += sumtbl[y][ex]-sumtbl[y][px-1];
        }
#endif
        return ret;
    };

    ll ans=0;
    for(ll h=H;h>=1;--h){
        for(ll w=W;w>=1;--w){
            ll sk=w*h*K;
            if(V<sk)continue;
            FOR(y,1,H+1){
                ll ey=y+h-1;
                if(ey>H)break;
                FOR(x,1,W+1){
                    ll ex=x+w-1;
                    if(ex>W)break;
                    ll v=calc_val(x,y,ex,ey);
                    if(V>=sk+v){
                        ans=max(ans,w*h);
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}