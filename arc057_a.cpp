//AtCoder ARC057 A - 2兆円
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,K; cin>>A>>K;
    ll yen=2e12;
#if 1
    ll t=A;
    ll day=0;
    if (t>=yen){
        //超えている
    } else if (K==0){
        day=yen-A;
    } else {
        while(t<yen){
            t=t+1+K*t;
            ++day;
        }
    }
    cout<<day<<endl;
#else //間違い
    if(K==1){
        ll n=yen-A+1;
        cout<<n<<endl;
    } else {
        double a=yen*(1-K)-1;
        double b=-1+(A-1)*(1-K);
        double kn=a/b;
        double n=log(kn)/log(K); //logk(Kn)こうなる
        cout<<(ll)ceil(n)<<endl;
    }
#endif
    return 0;
}