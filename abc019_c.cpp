//ABC019 C - 高橋くんと魔法の箱
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll divval(ll val){
    while(val%2==0){
		val /= 2;
	}
    return val;
}
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> atbl(N);
#if 1
    vector<ll> a2;
    a2.reserve(N);
    for(ll i=0; i<N;++i){
        cin>>atbl[i];
    }
    for(ll i=0; i<N;++i){
        ll tmp=divval(atbl[i]);
		a2.push_back(tmp);
	}
    sort(a2.begin(),a2.end());
    a2.erase(std::unique(a2.begin(), a2.end()), a2.end());
    cout<<a2.size()<<endl;
#else
    vector<ll> a2(N);
    for(ll i=0; i<N;++i){
        cin>>atbl[i];
    }
    sort(atbl.begin(),atbl.end());
    for(ll i=0; i<N;++i){
        a2[i]=atbl[i]*2;
    }
    ll ans=0;
    for (ll i=0; i<N;++i) {
        auto ret = binary_search(a2.begin(),a2.end(),atbl[i]);
        if (!ret){
            ++ans;
        }
    }
    cout<<ans<<endl;
#endif
    return 0;
}