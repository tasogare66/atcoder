//https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_b
//B - fLIP
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
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M,K; cin>>N>>M>>K;    
    bool ans=false;
    ll ttl=N*M;
    for(ll y=0;y<=N;++y){
        for(ll x=0;x<=M;++x){
            ll a=x*y;
            ll b=(N-y)*(M-x);
            ll num0=a+b;
            ll inv0=ttl-num0;
            if(num0==K||inv0==K){
                dump(x,y,num0,inv0);
                ans=true;
                cout<<"Yes"<<endl;
                exit(0);
            }
        }
    }
	cout << "No" << endl;
	return 0;
}