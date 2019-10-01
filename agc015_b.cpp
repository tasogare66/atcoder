//https://atcoder.jp/contests/agc015/tasks/agc015_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    ll ans=0;
    auto ue_kai = [&](ll k){
        return S.size()-k;
    };
    auto shita_kai = [&](ll k){
        return k-1;
    };
    FOR(i,0,S.size()){
        ll kai=i+1;
        if (S.at(i)=='U'){
            ans += ue_kai(kai);
            ans += shita_kai(kai)*2;
        }else{
            ans += ue_kai(kai)*2;
            ans += shita_kai(kai);
        }
    }
    cout<<ans<<endl;
    return 0;
}