//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

ll lcm(ll num1,ll num2){
	//return num1 / calc_gcd(num1,num2) * num2;
    return num1 / __gcd(num1,num2) * num2; //gcc拡張
}

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    auto cnt = [](ll v, ll c,ll d){
        ll b1=v/c;
        ll b2=v/d;
        ll b3=v/(lcm(c,d));
        return v-b1-b2+b3;
    };
    ll bb=cnt(B,C,D);
    ll aa=cnt(A-1,C,D);
    cout<<bb-aa<<endl;
    // ll b1=B/C;
    // ll b2=B/D;
    // ll b3=B/(C*D);
    // ll a1=(A-1)/C;
    // ll a2=(A-1)/D;
    // ll a3=(A-1)/(C*D);
    // ll ans=B-A+1-b1-b2+b3+a1+a2-a3;
    //cout<<ans<<endl;    
#if 0
    ll ans=0;
    for(ll i=A;i<=B;++i){
        ans+=(i%C!=0&&i%D!=0);
    }
#endif
    //cout<<ans<<endl;
    return 0;
}