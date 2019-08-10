//prime factorization
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

//約数を列挙 O(√N)
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

//素因数分解
//n,素因数分解する数
void PrimeFactorization(ll n, vector<int>& x){
    ll num=n;
	//for(int i = 2; i <= n; i++) {
	for(int i = 2; i <= num; i++) {
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

    auto r = divisor(16);
    for(auto v:r){
      cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}