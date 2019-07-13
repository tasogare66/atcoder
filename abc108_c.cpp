//AtCoder ABC108 C - Triangular Relationship
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,K; cin>>N>>K;
    //a%K==0
    ll num=N/K;
    ll ans=num*num*num;
    //a%K==K/2
    if(K%2==0){//Kが偶数
        ll k2=K/2;
        ll num2=(N+k2)/K;
        ans+=num2*num2*num2;
    }
    cout<<ans<<endl;
    return 0;
}