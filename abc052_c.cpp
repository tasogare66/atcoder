//AtCoder ABC052 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N=12;
    cin>>N;
    ll ans=1;

    int n=N;
	vector<int> x(n+1);
    for(int n=2;n<=N;++n){
		int num = n; // 素因数分解する変数num
		for(int i = 2; i <= n; i++) {
			while(num % i == 0) { //素数で割り切れなくなるまで割っていく
				x.at(i)++; //割った個数を配列に足す
				num /= i;
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		ans = ans * (x.at(i) + 1) % MOD; //それぞれを+1して掛けていく
	}
	cout << ans << endl;
	return 0;
}