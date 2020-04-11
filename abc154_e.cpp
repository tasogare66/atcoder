//https://atcoder.jp/contests/abc154/tasks/abc154_e
//E - Almost Everywhere Zero
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
    string N; cin>>N;
    ll K; cin>>K;    
    //vector<vector<vector<ll>>> dp_b(vector(N.size()+1,vector(2,vector<ll>(5))));
    vector<vector<vector<ll>>> dp_b(N.size()+1, vector<vector<ll>>(2, vector<ll>(5)));
    dp_b[0][0][0]=1;
    for(ll k=0;k<N.size();++k){ //桁
        ll digit = N[k]-'0';
        for(ll f=0;f<4;++f){ //0でない数字の数0,1,2,3,4以上
            for(ll d=0;d<=9;++d){ //未満フラグ1
                ll not0num = f + (d!=0);
                dp_b[k+1][1][not0num] += dp_b[k][1][f];
            }
            for(ll d=0;d<=digit;++d){ //未満フラグ0
                ll not0num = f + (d!=0);
                dp_b[k+1][(d<digit)][not0num] += dp_b[k][0][f]; //未満フラグ0は桁数があっているとき
            }
        }
    }
    ll bnum= dp_b[N.size()][0][K]+dp_b[N.size()][1][K];
    cout<<bnum<<endl;
 
    return 0;
}