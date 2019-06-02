//AtCoder ABC039 A - 高橋直体
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int ans = (a*b+b*c+a*c)*2;
    cout<<ans<<endl;
    return 0;
}