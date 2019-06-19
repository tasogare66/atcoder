//AtCoder ABC070 C - Multiple Clocks
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int64_t calc_gcd(int64_t a,int64_t b){
    if (a<b){
        swap(a,b);
    }
	int64_t r = a % b;
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
    return b;
}
ll lcm(ll num1,ll num2){
	//return num1 / calc_gcd(num1,num2) * num2;
    return num1 / __gcd(num1,num2) * num2; //gcc拡張
}

void PrimeFactorization(ll n, unordered_map<ll,ll>& x){
    ll num=n;
	//for(int i = 2; i <= n; i++) {
	for(ll i = 2; i <= num; i++) {
		while(num % i == 0) { //素数で割り切れなくなるまで割っていく
			x[i]++; //割った個数を配列に足す
			num /= i;
		}
	}
}

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> tn(N,0);
    for(auto&& t:tn){
        cin>>t;
    }
    ll ans=1;
    for(const auto& t:tn){
         ans=lcm(t,ans);
    }
    cout<<ans<<endl;
#if 0
    unordered_map<ll,ll> ans;
    for(const auto& t:tn){
		unordered_map<ll, ll> tmp;
		PrimeFactorization(t,tmp);
        for(const auto& t:tmp){
            ans[t.first] = max(ans[t.first], t.second);
        }
    }
    ll val=1;
    for(const auto& a:ans){
        val*=pow(a.first,a.second);
    }
    cout<<val<<endl;
#endif
    return 0;
}