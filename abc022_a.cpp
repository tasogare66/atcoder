//ABC022 A - Best Body
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int n,s,t;
    int w;
    cin>>n>>s>>t;
    cin>>w;
    auto check=[&](){
        return int(w>=s&&w<=t);
    };
    int ans=check();
    for (int i=0;i<n-1;++i) {
        int a;
        cin>>a;
        w += a;
        ans += check();
    }
    cout<<ans<<endl;
    return 0;
}