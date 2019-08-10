//https://atcoder.jp/contests/arc055/tasks/arc055_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    cout<<1;
    for(ll i=1;i<=N;++i){
        if(i==N){
            cout<<7<<endl;
        }else{
            cout<<0;
        }
    }    
    return 0;
}