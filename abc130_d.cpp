//AtCoder ABC130 D - Enough Array
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K;
    cin>>N>>K;
    vector<ll> atbl(N+1);
    vector<ll> sum(N+1);  //累積
    ll ttl=0;
    for (ll i=1;i<=N;++i){
        cin>>atbl[i];
        ttl+=atbl[i];
        sum[i]=ttl;
    }

    ll ans=0;
    ll prevj=-1;
    for(ll i=1;i<=N;++i){
        bool found=false;
        if (prevj>0){
            while(prevj>=i){
                ll v=sum[prevj]-sum[i-1];
                if(v<=K){
                    break;
                }
                --prevj;
            }
        }
        //for(ll j=i;j<=N;++j){
        for(ll j=max(prevj,i);j<=N;++j){
            ll v=sum[j]-sum[i-1];
            if (v>=K){
                ans+=N-j+1;
                prevj=j;
                found=true;
                break;
            }
        }
        if(!found)break;
    }
    cout<<ans<<endl;
    return 0;
}
