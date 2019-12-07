//https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_e
//E - 車の乗り継ぎ
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
    std::ifstream in("./test/sample-6.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,L; cin>>N>>L;
    ll VS,DS; cin>>VS>>DS;
    struct Info{
        ll x=0,v=0,d=0;
        double t=DBL_MAX;
    };
    vector<Info> tbl;
    Info s;
    s.x=0;
    s.v=VS;
    s.d=DS;
    s.t=0;
    tbl.push_back(s);
    REP(i,N){
        Info t;
        cin>>t.x>>t.v>>t.d;
        tbl.push_back(t);
    }
    Info g;
    g.x=L;
    tbl.push_back(g);
    sort(tbl.begin(),tbl.end(),[](auto&a,auto&b){ return a.x<b.x;});

    FOR(i,0,tbl.size()){
        const auto& d=tbl[i];
        double pt=d.x+d.d; //いけるところ
        FOR(j,i+1,tbl.size()){
            auto& cur=tbl[j];
            if (cur.x<=pt) {
                double lt= (double)(cur.x-d.x)/(double)d.v;
                cur.t=min(d.t+lt,cur.t);
            }else{
                break;
            }
        }
    }
    if(tbl.back().t!=DBL_MAX){
        cout<<fixed<<std::setprecision(10)<<tbl.back().t<<endl;
    }else{
        cout<<"impossible"<<endl;
    }

    return 0;
}