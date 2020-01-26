//https://atcoder.jp/contests/abc152/tasks/abc152_d
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

pair<ll,ll> gethf(ll v){
    auto f = v%10;
    ll h=0;
    while(v>0){
        h = v%10;
        v /= 10;
    }
    return {h,f};
}

int main(){
    ll N; cin>>N;
    vector<vector<ll>> mat(10,vector<ll>(10));
    FOR(i,1,N+1){
        auto p = gethf(i);
        mat[p.first][p.second]++;
    }
    ll ans=0;
    FOR(i,1,10){
        FOR(j,1,10){
            ans += mat[i][j] * mat[j][i];
        }
    }
    cout<<ans<<endl;

    return 0;
}

int main_() {
#if LOCAL&01
    //std::ifstream in("./test/sample-1.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;    
    vector<pair<ll,ll>> tmp;
    FOR(i,1,N+1){
        tmp.push_back(gethf(i));
    }
    dump(N,tmp.size())
    dump(tmp);
    ll cnt=0;
    FOR(i,0,tmp.size()){
        FOR(j,0,tmp.size()){
            auto& a=tmp[i];
            auto& b=tmp[j];
            if(a.first==b.second&& a.second==b.first){
                dump(i+1,j+1,a,b);
                ++cnt;
            }
        }
    }
    dump(cnt, cnt+tmp.size());

    return 0;
}