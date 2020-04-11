//https://atcoder.jp/contests/abc157/tasks/abc157_c
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

int main(){
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> lst(M);
    REP(i,M){
        cin>>lst[i].first>>lst[i].second;        
        lst[i].first -= 1;
    }

    auto check_val = [&](ll v)->bool{
        vector<ll> tbl;
        do {
            tbl.push_back(v%10);
            v /= 10;
        }while(v>0);
        reverse(tbl.begin(),tbl.end());
        bool ret=true;
        for(auto& p:lst){
            if(tbl.at(p.first) != p.second){
                ret = false;
                break;   
            }
        }
        return ret;
    };


    ll ans=-1;
    if (N==1){
        FOR(i,0,10){
            if (check_val(i)) {
                ans=i;
                break;
            }
        }
    }else if(N==2){
        FOR(i,10,100){
            if (check_val(i)) {
                ans=i;
                break;
            }
        }
    }else if(N==3){
        FOR(i,100,1000){
            if (check_val(i)) {
                ans=i;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


int main_() {
    ll N,M; cin>>N>>M;
    vector<ll> tbl(N,-1);
    bool ans=true;
    REP(i,M){
        ll s,c; cin>>s>>c;
        if (tbl.at(s-1)==c || tbl.at(s-1)==-1){
            tbl.at(s-1)=c;
        }else{
            ans=false;
            break;
        }
    }
    if(N==1){
        if(tbl.at(0)<0) {
            cout<<0<<endl;
            return 0;
        }
        cout<<tbl.at(0)<<endl;
        return 0;
    }
    if(tbl.at(0)==0)ans=false;
    if(ans){
        FOR(i,0,tbl.size()){
            if(tbl.at(i)<0) {
                tbl.at(i)=i==0?1:0;
            }
        }
    }

    if(ans){
        for(auto&&t:tbl){
            cout<<t;
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}