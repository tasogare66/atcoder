//https://www.hackerrank.com/contests/yfkpo3-2/challenges/books-rotation
//Books Rotation
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
    ll H,W; cin>>H>>W;
    vector<vector<ll>> ahw(H,vector<ll>(W));
    for(auto&& aw:ahw){
        for(auto&& a:aw){
            cin>>a;
        }
    }
    vector<ll> base;
    REP(y,H){
        base.emplace_back(ahw.at(y).at(0));
    }
    FOR(x,1,W){
        vector<ll> check(2*H);
        REP(y,H){
            check.at(y) = ahw.at(y).at(x);
            check.at(H+y) = ahw.at(y).at(x);
        }
        ll p=0;
        bool flag=false;
        for(ll y=0;y<check.size();++y){
            if(base.at(p)== check.at(y)){
                ++p;
            }else{
                p==0;
                if(base.at(p)== check.at(y)){
                    ++p;
                }
            }
            if(p==base.size()){
                flag=true;
                break;
            }
        }
        if(not flag){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}