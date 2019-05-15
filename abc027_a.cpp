//ABC027 A - 長方形
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    vector<int> l(3);
    cin>>l[0]>>l[1]>>l[2];
    sort(l.begin(),l.end());
    int ans=l[0];
    if (l[0]==l[1]) {
        ans=l[2];
    }
    cout<<ans<<endl;
    return 0;
}