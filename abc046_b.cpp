//AtCoder ABC046 B - AtCoDeerくんとボール色塗り / Painting Balls with AtCoDeer
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    lli N,K;
    cin>>N>>K;
    lli ans=1;
    for(int i=1;i<=N;++i){
        ans*=(i==1?K:K-1);
    }
    cout<<ans<<endl;
    return 0;
}