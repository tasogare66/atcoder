//https://atcoder.jp/contests/ddcc2019-final/tasks/ddcc2019_final_a
//A - レース (Race)
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
    string S; cin>>S;
    vector<ll> tbl;
    ll mxv=0;
    ll n=0;
    ll st=0,ed=0;
    ll mxst=0,mxed=0;
    REP(i,N){
        auto c=S.at(i);
        if(c=='>'){
            ++n;
            if(chmax(mxv,n)){
                mxst=st;
                mxed=i+1;
            }
        }else{
            n=0;
            st=i;
            ed=i;
        }
    }
    if(mxed>=N){
        S.at(mxst)='>';
    }else{
        S.at(mxed)='>';
    }

    double ans=0;
    ll k=0;
    REP(i,N){
        if(S.at(i)=='-'){
            ans += 1.0;
            k=0;
        } else {
            ans += 1.0/((double)k+2.0);
            ++k;
        }
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
}


int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string S; cin>>S;
    vector<ll> tbl;
    ll n=0;
    for(const auto& c:S){
        if(c=='-') {
            tbl.push_back(0);
            n=0;
        } else {
            if(n==0){
                tbl.push_back(1);
                n=1;
            }else{
                ++n;
                tbl.back()++;
            }
        }
    }
    ll prev=0;
    ll mxv=0;
    ll pt=0;
    FOR(i,0,tbl.size()){
        if(chmax(mxv,prev+tbl.at(i))){
            pt=i;
        }
        prev=tbl.at(i);
    }
    //
    double ans=0.0;
    tbl.at(pt)=1;

    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}