//https://atcoder.jp/contests/past201912-open/tasks/past201912_g
//G - 組分け / Division
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<vector<ll>> ann(N,vector<ll>(N+1,INT32_MAX));
    FOR(i,1,N+1){
        FOR(j,i+1,N+1){
            cin>>ann.at(i).at(j);
        }
    }

    ll ans=INT64_MIN;
    using member=vector<vector<char>>;
    auto calc_base = [&](const vector<char>& t){
        ll r=0;
        FOR(i,0,t.size()){
            int a=t[i];
            FOR(j,i+1,t.size()){
                int b=t[j];
                //dump(a,b);
                auto v=ann.at(a).at(b);
                assert(v<INT32_MAX);
                r += v;
            }
        }
        return r;
    };
    auto calc = [&](const member& m){
        ll r=0;
        for(auto& t:m){
            r+=calc_base(t);
        }
        return r;
    };
    function<void(int n, member m)> search = [&](int n, member m){
        if(N<=n){
            ll val=calc(m);
            ans=max(val,ans);
            return;
        }
        ++n;
        //dump(n);
        REP(i,3){
            m[i].push_back(n);
            search(n,m);
            m[i].pop_back();
        }
    };
    member st(3);
    search(0,st); //全探索
    cout<<ans<<endl;

    return 0;
}