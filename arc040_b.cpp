//https://atcoder.jp/contests/arc040/tasks/arc040_b
//B - 直線塗り
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
    ll N,R; cin>>N>>R;
    string S; cin>>S;
    //後ろから見る
    ll ans=0;
    ll max_p=0;
    for(ll i=S.size()-1;i>=0;--i){
        if(S.at(i)=='.'){
            //fill
            max_p=max(i-R+1,max_p);
            ++ans;
            for(ll p=i;i-p<R&&p>=0;--p){
                S.at(p)='o';
            }
        }
    }
    cout<<ans+max_p<<endl;
    return 0;
}