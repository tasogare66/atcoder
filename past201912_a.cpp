//https://atcoder.jp/contests/past201912-open/tasks/past201912_a
//A - 2 倍チェック / Is It a Number?
//Fまでやりたい
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
    string S; cin>>S;
    ll ans=0;
    for(auto c:S){
        if(c>='0'&&c<='9'){
            ans *= 10;
            ans += (c-'0');
        }else{
            cout<<"error"<<endl;
            return 0;
        }
    }
    cout<<ans*2<<endl;    
    return 0;
}