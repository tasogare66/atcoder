//AtCoder ABC044 A - 高橋君とホテルイージー / Tak and Hotels (ABC Edit)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,K;
    int X,Y;
    cin>>N>>K>>X>>Y;
    int ans=min(N,K)*X+max(0,N-K)*Y;
    cout<<ans<<endl;
    return 0;
}