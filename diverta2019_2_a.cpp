//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,K; //k人
    cin>>N>>K;
    ll ans=N-K;
    cout<<(K==1?0:ans)<<endl;
    return 0;
}