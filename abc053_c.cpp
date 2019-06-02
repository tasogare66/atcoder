//AtCoder ABC053 C - X: Yet Another Die Game
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll x;
    cin>>x;
    //6->5
    ll n=x/11;
    ll rest=x%11;
    ll ans=n*2;
    if(rest>0) {
		ans += (rest <= 6 ? 1 : 2);
	}
    cout<<ans<<endl;
    return 0;
}