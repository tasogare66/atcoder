//https://atcoder.jp/contests/arc046/tasks/arc046_b
//B - 石取り大作戦
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
    ll N; cin>>N;
    ll A,B; cin>>A>>B;
    //AがおおいとA勝ち確
    //Bがおおいとまえ以外B勝ち確 
    //同じだとAAABBBAAABBB(3だと)  
    if (A==B){
        ll n=N;
        bool t=false;
        while(n>0){
            t = !t;
            if(t) n -= A;
            else n -= 1;
        }
        cout<<(t?"Takahashi":"Aoki")<<endl;
    }else if(A>B){
        cout<<"Takahashi"<<endl;
    }else if(A<B){
        ll n=N;
        if (n-A<=0) cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
    }
    return 0;
}