//AtCoder ABC096 A - Day of Takahashi
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll a,b; 
    cin>>a>>b;
    ll ans=a-1;
    if(b>=a) ans+=1;
    cout<<ans<<endl;
    return 0;
}