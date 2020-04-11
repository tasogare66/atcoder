//https://atcoder.jp/contests/abc158/tasks/abc158_e
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
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,P; cin>>N>>P;
    string S; cin>>S;

    ll ans=0;
    FOR(s,0,N){
        ll v=S.at(s)-'0';
        ll rem = v%P;
        if(rem==0)++ans;
        dump(v,ans,rem);
        FOR(j,s+1,N){
            rem = rem*10+S.at(j)-'0';
            rem %= P;
            if(rem==0)++ans;
            // v *= 10;
            // v += S.at(j)-'0';
            // dump(s,j,v,ans,rem);
        }
    }
    cout<<ans<<endl;
    return 0;
}