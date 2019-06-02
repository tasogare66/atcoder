//AtCoder ABC048 B - Between a and b ...
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    lli a,b,x;
    cin>>a>>b>>x;
    lli st=max(a-1,(lli)0)/x;
    lli ed=b/x;
    lli ans=ed-st;
    if(a==0)++ans; //0だと加える
    cout<<ans<<endl;
    return 0;
}