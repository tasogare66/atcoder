//https://atcoder.jp/contests/arc040/tasks/arc040_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<string> sn(N);
    for(auto&& s:sn){
        cin>>s;
    }
    ll r=0,b=0;
    for(const auto& s:sn){
        for(const auto& c:s){
            if(c=='R') ++r; //takahashi
            else if(c=='B') ++b;
        }
    }
    if(r==b)cout<<"DRAW"<<endl;
    else if(r>b)cout<<"TAKAHASHI"<<endl;
    else cout<<"AOKI"<<endl;
    return 0;
}