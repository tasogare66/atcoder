//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,L;cin>>N>>L;
    ll min=INT64_MAX;
    ll ttl=0;
    ll mv=0;
	for(ll i = 1; i <= N; ++i) {
		ll v = L + i - 1;
		ttl += v;
		if(min > abs(v)) {
			min = abs(v);
			mv = v;
		}
	}
    cout<<ttl-mv<<endl;
	return 0;
}