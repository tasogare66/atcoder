//https://atcoder.jp/contests/agc021/tasks/agc021_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//[決めた桁][未満フラグ,未満のとき1]
ll dp[17][2]={};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string N; cin>>N;
    ll ans=0;
    REP(i,N.size()){
        if (N[i]=='0') continue;
        ll sum=0;
        REP(k,N.size()){
            ll digit = N[k]-'0';
            if(i==k){
                if (k==N.size()-1) sum+=digit;
                else sum+=digit-1;
            } else if(i<k){
                sum+=9;
            } else {
                sum+=digit;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
#if 0
    dp[0][0]=1;
    for(ll k=0;k<N.size();++k){ //桁
        ll digit = N[k]-'0';
        for(ll d=0;d<=9;++d){ //未満フラグ1
            //ll has49=f|(d==4||d==9);
            dp[k+1][1] = max(dp[k][1]+d,dp[k+1][1]);
        }
        for(ll d=0;d<=digit;++d){ //未満フラグ0
            //ll has49=f|(d==4||d==9);
            dp[k+1][(d<digit)] = max(dp[k][0]+d,dp[k+1][(d<digit)]); //未満フラグ0は桁数があっているとき
        }
    }
    ll ans=max(dp[N.size()][0],dp[N.size()][1]);
    cout<<ans<<endl;
    return 0;
#endif
}