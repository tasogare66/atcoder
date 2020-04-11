//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
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
    //000-999 が作れるか全探索
    ll N; cin>>N;
    string S; cin>>S;

    auto check_func = [&](array<ll,3>& pin)->bool{
        ll p=0;
        for(const auto& c:S){
            if(c-'0'==pin[p]){
                ++p;
                if(p>=pin.size()) return true; //trueだとつくれる
            }
        }
        return false;
    };

    ll ans=0;
    array<ll,3> pin;
    FOR(i,0,10){
        FOR(j,0,10){
            FOR(k,0,10){
                pin[0]=i;
                pin[1]=j;
                pin[2]=k;
                if (check_func(pin)) ++ans;
            }
        }
    }
    cout<<ans<<endl;    
    return 0;
}

int main_() {
    ll N; cin>>N;
    string S; cin>>S;
    vector<ll> tbl;
    for(auto& s:S){
        tbl.push_back(s-'0');
    }
    ll ans=0;
    set<ll> v0;
    for(ll l=0; l<N-2;++l){
        auto lval=tbl.at(l);
        if(v0.count(lval)!=0) continue;

        set<ll> v2;
        for(ll r=N-1;l+1<r;--r){
            auto rval=tbl.at(r);
            if(v2.count(rval)!=0) continue;

            set<ll> v1;
            for(ll mid=l+1;mid<r;++mid){
                auto mval=tbl.at(mid);
                if(v1.count(mval)==0) ++ans;
                v1.insert(tbl.at(mid));
            }
            v2.insert(tbl.at(r));
        }
        v0.insert(tbl.at(l));
    }
    cout<<ans<<endl;
    return 0;
}