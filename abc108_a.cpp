//AtCoder ABC108 A - Pair
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll K; cin>>K;
    ll od,ev;
    if(K%2==0){
		od = K / 2;
		ev = K / 2;
	}else{
		od = K / 2;
		ev = K / 2+1;
    }
	cout<<od*ev<<endl;
	return 0;
}