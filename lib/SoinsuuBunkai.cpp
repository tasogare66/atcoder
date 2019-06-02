//prime factorization
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

//素因数分解
//n,素因数分解する数
void PrimeFactorization(ll n, vector<int>& x){
    ll num=n;
	for(int i = 2; i <= n; i++) {
		while(num % i == 0) { //素数で割り切れなくなるまで割っていく
			x.at(i)++; //割った個数を配列に足す
			num /= i;
		}
	}
}

int main() {
    int test=5000;
    vector<int> a(5000+1,0);
    PrimeFactorization(test,a);
    //約数の個数
    ll ans=1;
	for(int i = 2; i <= test; ++i) {
		ans = ans * (a.at(i) + 1); //それぞれを+1して掛けていく
	}
    cout<<ans<<endl;
    return 0;
}