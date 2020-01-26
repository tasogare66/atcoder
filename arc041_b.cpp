//https://atcoder.jp/contests/arc041/tasks/arc041_b
//B - アメーバ
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
    ll N,M; cin>>N>>M;
    vector<string> ibn(N);
    for(auto&& b:ibn){
        cin>>b;
    }
    vector<vector<ll>> bn(N,vector<ll>(M,0));
    auto an=bn;
    REP(y,N){
        REP(x,M){
            bn.at(y).at(x) = ibn.at(y).at(x) - '0';
        }
    }

    auto get_val = [&](const auto& tbl, ll y,ll x)->ll{
        if(y<0||y>=N) return 0;
        if(x<0||x>=M) return 0;
        return tbl.at(y).at(x);
    };
    auto sub_val = [&](ll y,ll x, ll val){
        assert(x>=0&&x<M);
        assert(y>=0&&y<N);
        bn.at(y).at(x) -= val;
    };
    REP(y,N){
        REP(x,M){
            ll tmp=INT64_MAX;
            chmin(tmp,get_val(bn, y-1,x));
            chmin(tmp,get_val(bn, y+1,x));
            chmin(tmp,get_val(bn, y,x-1));
            chmin(tmp,get_val(bn, y,x+1));
            if (tmp>0){
                sub_val(y-1,x,tmp);
                sub_val(y+1,x,tmp);
                sub_val(y,x-1,tmp);
                sub_val(y,x+1,tmp);
                an.at(y).at(x) += tmp;
            }
        }
    }
    REP(y,N){
        REP(x,M){
            cout<<get_val(an, y,x);
        }
        cout<<endl;
    }
    return 0;
}