//https://atcoder.jp/contests/agc040/tasks/agc040_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
    {
        //test
        vector<int64_t> tst={INT32_MAX,10,10};
        int64_t tmp0 = accumulate(tst.begin(),tst.end(),0);
        int64_t tmp2 = accumulate(tst.begin(),tst.end(),0LL);
        int64_t tmp1=0;
        for(const auto& v:tst){
            tmp1+=v;
        }
        dump(tmp0,tmp1,tmp2);
    }
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string S; cin>>S;
    vector<ll> an(S.size()+1,0);
    vector<ll> bn(S.size()+1,0);
    for(ll i=0;i<S.size();++i){
        if(S.at(i)=='<'){
            an.at(i+1)=max(an.at(i)+1,an.at(i+1));
        } else {
            bn.at(i+1)=max(bn.at(i)+1,bn.at(i+1));
        }
    }
    for(ll i=S.size()-1;i>=0;--i){
        if(S.at(i)=='>'){
            an.at(i)=max(an.at(i),an.at(i+1)+1);
        } else{
            bn.at(i)=max(bn.at(i),bn.at(i+1)+1);
        }
    }
    ll ans=0;
    for(const auto& a:an){
        ans+=a;
    }
    cout<<ans<<endl;
    return 0;
}