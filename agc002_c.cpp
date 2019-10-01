//https://atcoder.jp/contests/agc002/tasks/agc002_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,L; cin>>N>>L;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    bool possible=false;
    ll pos=0;
    REP(i,N-1){
        if(an.at(i)+an.at(i+1) >= L){
            possible = true;
            pos=i;
            break;
        }
    }
    if(possible){
        cout<<"Possible"<<endl;
        //posに対して両端から挟むように
        for(ll i=0;i<pos;++i){
            cout<<i+1<<endl;
        }
        for(ll i=N-2;(i>pos&&i>=0);--i){
            cout<<i+1<<endl;
        }
        cout<<pos+1<<endl;
    } else {
        //assert(0);
        cout<<"Impossible"<<endl;
    }

    return 0;
}