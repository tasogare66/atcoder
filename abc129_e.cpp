//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;
//[桁][未満フラグ,未満で1]
//条件は桁が違う場合1
ll dp[100001+10][2];

int main() {
    string L;
    cin>>L;
    dp[0][0]=1;
    for(ll k=0;k<L.size();++k){
		ll digit = L[k] - '0';
		for(ll d = 0; d < 2; ++d) { //未満フラグ1
            if(d==0){
				(dp[k + 1][1] += dp[k][1]) %= MOD;
			} else {
				(dp[k + 1][1] += dp[k][1]) %= MOD; //0と1がいける
                (dp[k + 1][1] += dp[k][1]) %= MOD;
            }
		}
		for(ll d = 0; d <= digit; ++d) { //未満フラグ0
            if(d==0){
			    (dp[k + 1][d < digit] += dp[k][0]) %= MOD;
            }else {
			    (dp[k + 1][d < digit] += dp[k][0]) %= MOD; //0と1がいける
			    (dp[k + 1][d < digit] += dp[k][0]) %= MOD;
            }
		}
	}
    cout<<(dp[L.size()][0]+dp[L.size()][1])%MOD<<endl;
    return 0;
}