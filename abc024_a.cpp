//ABC024 A - 動物園
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int a,b,c,k;
    int s,t;
    cin>>a>>b>>c>>k;
    cin>>s>>t;
    int ans=a*s+b*t;
	auto st = s + t;
    if (st>=k){
        ans-=st*c;
    }
	cout<<ans<<endl;
    return 0;
}