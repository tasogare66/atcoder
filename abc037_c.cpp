//AtCoder ABC037 C - 総和
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,K;
#if 0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>K;
    vector<int> atbl(N+1,0);
    vector<lli> sum(N+1,0);
    lli s=0;
    for(int i=1;i<=N;++i){
        cin>>atbl[i];
        s+=atbl[i];
        sum[i]=s;
    }
    lli ans=0;
    for(int i=1;i<=N-K+1;++i){
        lli tmp= sum[K+i-1]-sum[i-1];
        ans += tmp;
    }
    cout<<ans<<endl;
    return 0;
}