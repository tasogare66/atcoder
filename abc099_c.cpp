//AtCoder ABC099 C - Strange Bank
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

ll kj(ll v, ll lim){
    ll ret=1;
    while(ret*v<=lim){
        ret*=v;
    }
    return ret;
}

ll search(ll n,ll cnt){
    if(n<6){
        return cnt+n; //残りの回数
    }

    auto i=kj(6,n);
    auto j=kj(9,n);
    ll c6=INT64_MAX,c9=INT64_MAX;
    if(i>1){
        c6=search(n-i,cnt+1);
    }
    if(j>1){
        c9=search(n-j,cnt+1);
    }
    return min(c6,c9);
}

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    ll ans=search(N,0);
    cout<<ans<<endl;
    return 0;
}