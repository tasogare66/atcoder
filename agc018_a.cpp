//https://atcoder.jp/contests/agc018/tasks/agc018_a
//A - Getting Difference
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    bool ans=false;
    for(auto&& a:an){
        cin>>a;
        if (K<=a) ans=true;
    }
    assert(an.size()>=1);
    ll gcdv=an[0];
    FOR(i,1,N){
        gcdv=__gcd(gcdv,an[i]);
    }
    ans &= (K%gcdv==0);
#if 0
    sort(an.begin(),an.end());

    vector<ll> candidate;
    for(const auto& a:an){
        auto df=a-K;
        if(df>=0) candidate.push_back(df);
    }

    bool ans=false;
    for(ll i=0;i<an.size();++i){
        for(ll j=i+1;j<an.size();++j){
            auto val = abs(an[i]-an[j]);
            if (val==0) continue;
            for(auto& cv:candidate){
                if(cv%val==0){
                    ans=true;
                    break;
                }
            }
        }
    }
#endif
    cout<<(ans?"POSSIBLE":"IMPOSSIBLE")<<endl;
    return 0;
}