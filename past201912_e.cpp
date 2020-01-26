//https://atcoder.jp/contests/past201912-open/tasks/past201912_e
//E - SNS のログ / Restore
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
    ll N, Q; cin>>N>>Q;
    vector<vector<bool>> cur(N+1,vector<bool>(N+1,false));
    vector<vector<bool>> prv(N+1,vector<bool>(N+1,false));

    auto fol = [&](ll a, ll b, bool flag){
        if(a==b)return; //おなじはしない
        cur.at(a).at(b)=flag;
    };

    REP(q,Q){
        ll type; cin>>type;
        if (type==1){
            ll a,b; cin>>a>>b;
            fol(a,b,true);
        }else if(type==2){
            ll a; cin>>a;
            FOR(b,1,N+1){
                if(cur.at(b).at(a)){
                    fol(a,b,true);
                }
            }
        }else if(type==3){
            prv = cur; //全部copy
            ll a; cin>>a;
            FOR(x,1,N+1){
                if(prv.at(a).at(x)){
                    FOR(b,1,N+1){
                        if(prv.at(x).at(b)){
                            fol(a,b,true);
                        }
                    }
                }
            }            
        }else {
            assert(0);
        }
    }

    FOR(a,1,N+1){
        FOR(b,1,N+1){
            char c=cur.at(a).at(b)?'Y':'N';
            cout<<c;
        }
        cout<<endl;
    }

    return 0;
}