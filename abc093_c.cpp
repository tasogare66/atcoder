//AtCoder ABC093 C - Same Integers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    vector<ll> abc(3);
    cin>>abc[0]>>abc[1]>>abc[2];
    sort(abc.begin(),abc.end());
    ll dif0=abc[2]-abc[1];
    ll dif1=abc[2]-abc[0]; //こっちがおおきい
    ll ans=dif0;
    dif1-=dif0;
    ans+=(dif1/2);
    if(dif1%2==1)ans+=2; //残りがあるなら+2
    cout<<ans<<endl;
    return 0;
}