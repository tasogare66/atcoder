//AtCoder ABC103 C - Modulo Summation
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2; //gcc拡張
}
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll m=lcm(an[0],an[1]);
#if LOCAL
    cout<<an[0]<<","<<an[1]<<endl;
    cout<<m<<endl;
#endif
    for(ll i=2;i<N;++i){
        m=lcm(m,an[i]);
    }
    --m;
#if LOCAL
    cout<<m<<endl;
#endif
    ll ans=0;
    for(const auto& a:an){
        //ans+=(m%a);
        ans+=(a-1); //結局最大はa-1余るので
    }
    cout<<ans<<endl;
    return 0;
}