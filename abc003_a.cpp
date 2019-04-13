//ABC002 A - AtCoder社の給料
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    double ans;
    for(int i=1;i<=n;++i){
        ans += i * 10000;
    }
    ans /= (double)n;
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}