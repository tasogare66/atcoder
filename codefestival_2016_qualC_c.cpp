//https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_c
//C - 二人のアルピニスト / Two Alpinists
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
constexpr ll MOD=1e9+7;
int main() {
    ll N; cin>>N; 
    vector<ll> tn(N),an(N);
    for(auto&& t:tn){
        cin>>t;
    }
    for(auto&& a:an){
        cin>>a;
    }
    ll tmx=*(tn.end()-1);
    ll amx=*an.begin();
    if (tmx!=amx) {cout<<0<<endl; return 0;} 
    vector<ll> tt(N,0),aa(N,0);
    ll mx=0;
    ll tno=-1,ano=-1;
    REP(i,N){
        const auto t=tn.at(i);
        if(tno<0&&tmx==t) tno=i;
        if(mx>t) {cout<<0<<endl; return 0;}
        if(!chmax(mx,t)){
            tt.at(i)=t;
        }
    }
    mx=0;
    for(ll i=N-1;i>=0;--i){
        const auto a=an.at(i);
        if(ano<0&&amx==a) ano=i;
        if(mx>a) {cout<<0<<endl; return 0;}
        if(!chmax(mx,a)){
            aa.at(i)=a;
        }
    }
    if(tno>ano){cout<<0<<endl; return 0;}
    ll ans=1;
    REP(i,N){
        if(tt.at(i)<=0||aa.at(i)<=0){
        } else {
            ll n=min(tt.at(i),aa.at(i));
            ans *= n;
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}