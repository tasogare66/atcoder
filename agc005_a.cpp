//https://atcoder.jp/contests/agc005/tasks/agc005_a
//A - STring
//累積和s,tのカウント、tの時点でtが多い分は残る
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string x; cin>>x;
    ll tn=0,sn=0;
    ll ans=0;
    REP(i,x.size()){
        if(x[i]=='T'){
            ++tn;
            ans=max(ans,tn-sn);
        } else {
            ++sn;
        }
    }
    cout<<ans*2<<endl;
    return 0;
}
