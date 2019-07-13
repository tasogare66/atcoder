//AtCoder ABC103 A - Task Scheduling Problem
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    vector<ll> a3(3+1);
    vector<ll> id={1,2,3};
    for(ll i=1;i<=3;++i){
        cin>>a3[i];
    }
    ll ans=INT64_MAX;
	do {
		ll cst=0;
        cst+=abs(a3[id[1]]-a3[id[0]]);
        cst+=abs(a3[id[2]]-a3[id[1]]);
        ans=min(ans,cst);
    } while (std::next_permutation(id.begin(), id.end()));
    cout<<ans<<endl;
    return 0;
}
