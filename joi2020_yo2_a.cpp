//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_a
//A - ポスター (Poster)
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
    ll N; cin>>N;
    vector<string> snn(N);        
    for(auto&& sn:snn){
        cin>>sn;
    }
    vector<string> tnn(N);
    for(auto&& tn:tnn){
        cin>>tn;
    }
    auto check_diff = [N](const vector<string>& a, const vector<string>& b)->ll{ //違っている箇所を返す
        assert(a.size()==b.size());
        ll count=0;
        FOR(y,0,a.size()){
            FOR(x,0,N){
                if(a[y].at(x)!=b[y].at(x)) ++count;
            }
        }
        return count;
    };
    auto rot_r = [N](const vector<string>& a){
        auto out = a;
        FOR(y,0,N){
            FOR(x,0,N){
                out[x][N-y-1]=a[y][x];
            }
        }
        return out;
    };
    ll ans=INT64_MAX;
    //まま
    ans=check_diff(snn,tnn);
    //右
    auto tmp = rot_r(snn);
    ans = min(ans,check_diff(tmp, tnn)+1);
    //反転
    tmp = rot_r(tmp);
    ans = min(ans,check_diff(tmp, tnn)+2);
    //左
    tmp = rot_r(tmp);
    ans = min(ans,check_diff(tmp, tnn)+1);

    cout<<ans<<endl;
    return 0;
}