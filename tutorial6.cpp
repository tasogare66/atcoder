//ABC083B - Some Sums
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    cin>>a>>b;
    int ans=0;
    for (int i=1; i<=n;++i){
        int keta_sum = 0;
        auto tmp = i;
        while (tmp>0) {
            keta_sum += (tmp % 10);
            tmp /= 10;
        }
        if (keta_sum >=a && keta_sum <= b) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}