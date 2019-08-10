//https://atcoder.jp/contests/abc135/tasks/abc135_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
constexpr ll MOD=1e9+7;
ll dp[100007][13]={};
int main() {
#if LOCAL&0
    //13で割って5余る、6桁
    for(ll i=1;i<1000;++i){
        cout<<13*i+5<<endl;
    }
#endif    
    string S; cin>>S;
    auto get_val = [&](ll p){ //-1だと?
        if(S[p]=='?'){
            return -1;
        }
        return S[p]-'0';
    };
    ll s=get_val(0);
    if(s<0){
        for(ll i=0;i<=9;++i){
            dp[0][i]=1;
        }
    } else {
        dp[0][s]=1;
    }
    for(ll i=1;i<S.size();++i){
        ll v=get_val(i);
        for(ll d=0;d<=9;++d){ //今のけたの数字
            if(v==d||v<0){
            for(ll p=0;p<13;++p){ //前の桁あまり
                ll r=(p*10+d)%13;
                dp[i][r] += dp[i-1][p];
                dp[i][r] %= MOD;
            }
            }
        }
    }
    cout<<dp[S.size()-1][5]<<endl;
    return 0;
}