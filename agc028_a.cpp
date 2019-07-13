//AtCoder AGC028 A - Two Abbreviations
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,M; cin>>N>>M;
    string S,T; cin>>S>>T;
    ll ans=lcm(N,M); //ans
    //vector<char> x(ans+1,0);
    unordered_map<ll,char> x;
    ll step=ans/N;
    REP(i,S.size()){
        x[1+step*i]=S[i];
    }
    step=ans/M;
    REP(i,T.size()){
        auto ch=T[i];
        auto it=x.find(1+step*i);
        if(it==x.end()) continue;
        if(it->second!=ch){
            ans=-1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}