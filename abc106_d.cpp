//https://atcoder.jp/contests/abc106/tasks/abc106_d
//D - AtCoder Express 2
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
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M,Q; cin>>N>>M>>Q;
    struct Data{
        ll s,e;
        bool query=false;
        ll query_id=-1;
    };    
    vector<Data> total; //query,data両方いれて終端でsortする
    total.reserve(M+Q);
    REP(i,M){
        ll l,r; cin>>l>>r;
        Data d;
        d.s=l;
        d.e=r;
        total.push_back(d);
    }
    //query
    REP(i,Q){
        ll p,q; cin>>p>>q;
        Data d;
        d.s=p;
        d.e=q;
        d.query=true;
        d.query_id=i;
        total.push_back(d);
    }
    sort(total.begin(),total.end(),[](const auto& a,const auto& b){
        if (a.e==b.e) return a.query_id<b.query_id; //queryを後ろにする
        return a.e<b.e;
    }); //終端でsort
    vector<ll> cnttbl(N+1);
    vector<ll> ans(Q);
    for(auto& d:total){
        if(d.query){
            FOR(p,d.s,d.e+1){
                ans.at(d.query_id) += cnttbl.at(p);
            }
        }else{
            cnttbl.at(d.s)++;
        }
    }
    for(const auto& a:ans){
        cout<<a<<endl;
    }
    return 0;
}