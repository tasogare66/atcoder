//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll N;
ll search_num(vector<ll>& vtbl){
    ll ans=0;
	do {
		ll val = 0;
		for(auto &&v : vtbl) {
			val *= 10;
			val += v;
		}
        cout<<val<<endl;
		if(val <= N) ++ans;
	} while(std::next_permutation(vtbl.begin(), vtbl.end()));
    return ans;
}
ll search(vector<ll> tbl, ll keta){
    ll ans = search_num(tbl);
    if (keta<=tbl.size())return ans;
	for(auto &n : {3, 5, 7}) {
		auto tmp = tbl;
        tmp.push_back(n);
        sort(tmp.begin(),tmp.end());
        ans += search(tmp, keta);
	}
    return ans;
}
int main() {
#if LOCAL&01
    vector<ll> tmp={3,3,5,7};
    search_num(tmp);
    return 0;
#endif
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N;
    ll keta=0;
    {
        ll n=N;
        while(n>0){
            n/=10;
            ++keta;
        }    
    }
    vector<ll> vtbl={3,5,7};
    ll ans=search(vtbl, keta);
    cout<<ans<<endl;
    return 0;
}