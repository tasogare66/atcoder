//AtCoder ABC132 B - Ordinary Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll n; cin>>n;
    vector<ll> pn(n);
    for(auto&& p:pn){
        cin>>p;
    }
    ll ans=0;
    for(ll i=1;i<pn.size()-1;++i){
        vector<ll> tmp(3);
        tmp[0]=pn[i-1];
		tmp[1]=pn[i];
       	tmp[2]=pn[i+1];
        sort(tmp.begin(),tmp.end());
        if(tmp[1]==pn[i] && tmp[0]!=pn[i]) ++ans;
	}
    cout<<ans<<endl;
    return 0;
}