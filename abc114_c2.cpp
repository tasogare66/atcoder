//AtCoder ABC114 C - 755
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll N;
ll check_val(vector<ll>& vtbl){
    ll ans=0;
    bool has[10]={};
	{
		ll val = 0;
		for(auto &&v : vtbl) {
            has[v]=true;
			val *= 10;
			val += v;
		}
        //cout<<val<<endl;
		if(val <= N && has[3]&&has[5]&&has[7]) ++ans;
	}
    return ans;
}
ll search(vector<ll> tbl, ll keta){
    ll ans = 0;//search_num(tbl);
    if (keta<=tbl.size())return ans;
	for(auto &n : {3, 5, 7}) {
		auto tmp = tbl;
        tmp.push_back(n);
        ans += check_val(tmp);
        ans += search(tmp, keta);
	}
    return ans;
}
int main() {
    cin>>N;
    ll keta=0;
    {
        ll n=N;
        while(n>0){
            n/=10;
            ++keta;
        }    
    }
    vector<ll> vtbl;
    ll ans=search(vtbl, keta);
    cout<<ans<<endl;
    return 0;
}