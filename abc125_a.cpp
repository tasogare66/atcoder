//ABC125 A - Biscuit Generator
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    float tt;
    cin>>a>>b>>tt;
    tt+=0.5;
    int t=a;
    int ans=0;
    //int cnt=1;
	while((float)t < tt) {
		ans += b;
		t += a;
        //++cnt;
	}
    cout<<ans<<endl;
    return 0;
}