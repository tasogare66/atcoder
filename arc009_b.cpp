//https://atcoder.jp/contests/arc009/tasks/arc009_2
//B - おとぎの国の高橋君
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
    vector<ll> b10(10);
    FOR(i,0,10){
        ll b; cin>>b;
        b10[b]=i;
    }
    ll N; cin>>N;

    auto value = [&](ll v){
        ll result=0;
        ll keta=1;
        while(v>0){
            auto d = v % 10;
            result += b10.at(d) * keta;
            keta *= 10;
            v /= 10;
        }
        return result;
    };

    dump(value(8));

    vector<pair<ll,ll>> an(N);
    for(auto&& a:an){
        cin>>a.second;
        a.first = value(a.second);
    }
    sort(an.begin(),an.end());
    for(const auto& p:an){
        cout<<p.second<<endl;
    }
    return 0;
}
