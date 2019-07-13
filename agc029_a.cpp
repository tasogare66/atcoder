//AtCoder AGC029 A - Irreversible operation
//Wを左にずらした回数、wの位置の累積和-wの個数の累積和
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    ll sum1=0;
    ll num=0;
    ll sum2=0;
    REP(i,S.size()){
        if(S[i]=='W'){
            sum1+=i;
            sum2+=num;
            ++num;
        }
    }
    ll ans=sum1-sum2;
    cout<<ans<<endl;
    return 0;
}