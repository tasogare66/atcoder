//AtCoder B - Some Sums
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,A,B;
    cin>>N>>A>>B;
    ll ans=0;
    auto check_keta = [&](ll n){
        ll kw=0;
        while(n > 0){
            kw += n%10;
            n /= 10;
        }
        return (kw>=A&&kw<=B);
    };
    for(ll i=1;i<=N;++i){
        if (check_keta(i)) ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}