//AtCoder ABC040 B - □□□□□
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int n;
    cin>>n;
    lli ans=INT32_MAX;
    for(int i=1;i<=n/2+1;++i){
        lli a=i;
        lli b=n/a;
        lli area=a*b;
        ans=std::min(abs(a-b)+n-area,ans);
    }
    cout<<ans<<endl;
    return 0;
}