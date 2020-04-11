//https://atcoder.jp/contests/arc036/tasks/arc036_b
//B - 山のデータ
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
    ll N; cin>>N;
    vector<ll> hn(N+1);
    FOR(i,1,N+1){
        cin>>hn.at(i);
    }    

    ll ans=0;
    ll now_size=0;
    ll is_down=false;
    FOR(i,1,N+1){
        auto cur = hn.at(i);
        auto prv = hn.at(i-1);
        if(cur>prv){
            //のぼり
            if(is_down){
                //reset
                is_down=false;
                now_size=2;
            } else{
                ++now_size;
            }
        } else if(cur<prv){
            //くだり
            is_down = true;
            ++now_size;
        } else {
            ++now_size;
        }
        ans=max(ans,now_size);
    }
    cout<<ans<<endl;
    return 0;
}