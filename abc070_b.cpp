//AtCoder ABC070 B - Two Switches
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    ll ans=0;
    ll base=min(B-A,D-C);
    if(A>D||C>B){
        //0
    } else if(B>D){
		ans = min(D - A, base);
	} else {
    	ans = min(B - C, base);
    }
    cout<<ans<<endl;
	return 0;
}