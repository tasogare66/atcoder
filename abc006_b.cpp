//ABC006 B - トリボナッチ数列
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    std::vector<int> a(n,0);
    if (a.size() >= 1) a[0] = 0;
    if (a.size() >= 2) a[1] = 0;
    if (a.size() >= 3) a[2] = 1;
    for (int i=3;i<n;++i) {
        a[i] = (a[i - 3] + a[i - 2] + a[i - 1])%10007;
    }
    cout<<a[n-1]<<endl;
    return 0;
}