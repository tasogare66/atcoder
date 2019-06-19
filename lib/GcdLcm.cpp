//最大公約数(gcd)、最小公倍数(lcm)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

//最大公約数
//__gcd(num1,num2) * num2; //gcc拡張
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
//最小公倍数
ll lcm(ll num1,ll num2){
	//return num1 / calc_gcd(num1,num2) * num2;
    return num1 / __gcd(num1,num2) * num2; //gcc拡張
}

int main() {
    cout<<calc_gcd(12,684)<<endl;
    cout<<lcm(10,648)<<endl;
    return 0;
}