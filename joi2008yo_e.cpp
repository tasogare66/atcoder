//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
//E - おせんべい
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
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll R,C; cin>>R>>C;
    vector<vector<int>> mat(R,vector<int>(C));
    for(auto&& ys:mat){
        for(auto&& x:ys){
            cin>>x;
        }
    }

    auto calc_num = [&](ll bits)->ll{
        ll cnt=0;
        FOR(x,0,C){
            ll tmp=0;
            FOR(y,0,R){
                ll flag = (bits>>y)&1LL;
                if(mat.at(y).at(x) ^ flag) ++tmp;
            }
            cnt += max(tmp,R-tmp);
        }
        return cnt;
    };

    ll ans=0;
    ll max_bit=1LL<<R;
    FOR(m,0,max_bit){
        ll num=calc_num(m);
        dump(m,num);
        ans=max(ans,num);
    }
    cout<<ans<<endl;

    return 0;
}