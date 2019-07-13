//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll N,A,B,C;
vector<ll> ln;
ll search_func(ll i,ll a,ll b, ll c, ll mp){
    if (i>=N){
        if(a<=0||b<=0||c<=0) return INT64_MAX;
        mp+=abs(A-a)+abs(B-b)+abs(C-c);
        return mp;
    }
    //a
    ll ret = search_func(i+1,a+ln[i],b,c,a>0?mp+10:mp);
    //b
    ret = min(search_func(i+1,a,b+ln[i],c,b>0?mp+10:mp),ret);
    //c
    ret = min(search_func(i+1,a,b,c+ln[i],c>0?mp+10:mp),ret);
    //使わない
    ret = min(search_func(i+1,a,b,c,mp),ret);
    return ret;
}

int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>A>>B>>C; 
    ln.resize(N);
    for(auto&& l:ln){
        cin>>l;
    }
    ll ans=search_func(0,0,0,0,0);
    cout<<ans<<endl;
    return 0;
}