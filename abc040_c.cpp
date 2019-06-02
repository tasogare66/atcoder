//AtCoder ABC040 C - 柱柱柱柱柱
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<int> atbl(N+1,0);
    vector<lli> dp(N+1,0);
    dp[0]=INT32_MAX;
    for(int i=1;i<=N;++i){
        cin>>atbl[i];
    }
    for(int i=2;i<=N;++i){
        lli p1 = abs(atbl[i]-atbl[i-1])+dp[i-1];
        lli p2 = abs(atbl[i]-atbl[i-2])+dp[i-2];
        dp[i]=min(p1,p2);
    }
    cout<<dp[N]<<endl;
    return 0;
}