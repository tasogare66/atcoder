//AtCoder ABC102 C - Linear Approximation
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll BinarySearch(ll low, ll high, std::function<bool(ll)> check){
    if(high-low==1){
        return low;
    }
    ll mid = (high+low)/2; 
    if(check(mid)){
        return BinarySearch(mid, high, check);
    }else{
        return BinarySearch(low, mid, check);
    }
}
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-3.in");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    vector<ll> bn(N+1,0);
    ll minv=INT64_MAX,maxv=0;
    for(ll i=1;i<=N;++i){
        ll a; cin>>a;
        an[i]=a;
        bn[i]=a-i;
        minv=min(a,minv);
        maxv=max(a,maxv);
    }
    sort(bn.begin()+1,bn.end()); //0は未使用なので
    auto calca = [&](ll b){
        ll ret=0;
        for(ll i=1;i<=N;++i){
            ret += abs(an[i]-(b+i));
        }
        return ret;
    };
    auto calcb = [&](ll b){
        ll ret=0;
        for(ll i=1;i<=N;++i){
            ret += abs(bn[i]-b);
        }
        return ret;
    };
#if LOCAL&0
    //test
    ll tmp=INT64_MAX;
    for(ll i=bn[0];i<=bn.back();++i){
        auto t=calcb(i);
        tmp=min(tmp,t);
        cout<<i<<","<<tmp<<endl;
    }
    cout<<tmp<<endl;
#endif
    ll ans=INT64_MAX;
    ans=min(calcb(bn[N/2]),ans);
    ans=min(calcb(bn[N/2+1]),ans);
    cout<<ans<<endl;
    return 0;
}