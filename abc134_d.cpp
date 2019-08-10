//https://atcoder.jp/contests/abc134/tasks/abc134_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N+1);
    for(ll i=1;i<=N;++i){
        cin>>an[i];
    }
    vector<ll> bn(N+1,0);
    ll num=0;
    for(ll i=N;i>=1;--i){ //うしろから決める
        ll sum=0;
        for(ll j=i;j<=N;j+=i){
            sum+=bn[j];
        }
        if(sum%2!=an[i]){
            bn[i]=1;
            ++num;
        }
    }
    cout<<num<<endl;
    bool fst=true;
    for(ll i=1;i<=N;++i){
        if (bn[i]) {
            if(!fst){
                cout<<" ";
            }
            fst=false;
            cout<<i;
        }
    }
    if(!fst) cout<<endl;
    return 0;
}