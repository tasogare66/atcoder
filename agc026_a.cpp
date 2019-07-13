//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
	ll ans=0;
    for(ll i=1;i<an.size();++i){
        if (an[i]==an[i-1]){
            ++ans;
            ++i;
        }
    }
    cout<<ans<<endl;
	return 0;
}