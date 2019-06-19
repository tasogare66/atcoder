//AtCoder ABC055 B - Training Camp
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;

int main() {
    int N;
    cin>>N;
    ll ans=1;
    for(int i=1;i<=N;++i){
        ans *= i;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}