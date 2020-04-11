//https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d
//D - 壊れた電卓
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
#if LOCAL&0
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string A; cin>>A;
    ll K; cin>>K;
    ll la = atoll(A.c_str());
    dump(la);

    //左からP桁目までAと同じ
    //左からP+1桁目をQ
    //左からP+2桁目以降をRにする
    auto get_val = [&](ll p, ll q, ll r)->ll{
        ll val= 0;
        ll mask=0;
        FOR(i,0,min<ll>(p,A.size())){
            val *= 10;
            ll digit = A.at(i)-'0';
            //mask |= (1<<digit);
            val += digit;
        }
        if (p+1<=A.size()) {
            val = val*10+q;
            //mask |= (1<<q);
        }
        FOR(i,p+2,A.size()+1){
            val *= 10;
            val += r;
            //mask |= (1<<r);
        }
        //ll num = __builtin_popcountll(mask);
        //if (num>K) return -1;
        return val;
    };
    auto check_val = [&](ll val)->bool{
        ll cnt=0;
        set<ll> tbl;
        while(val >0 ){
            tbl.insert(val % 10);
            val /= 10;
        }
        return (K>=tbl.size());
    };

    dump(get_val(2,9,8));

    ll ans=INT64_MAX;
    FOR(p,0,min<ll>(K+1,A.size()+1)){
        FOR(q,0,10){
            FOR(r,0,10){
                ll val = get_val(p,q,r);
                if(!check_val(val))continue;
                dump(val,p,q,r);
                ll dif = abs<ll>(la - val);
                if (chmin(ans,dif)){
                    dump(val);
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main_() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string A; cin>>A;
    ll K; cin>>K;
    ll la = atoll(A.c_str());

    function<ll(ll,ll,ll)> dfs = [&](ll keta, ll val, ll mask)->ll{
        if(keta>=A.size()){
            //dump(val);
            return std::abs<ll>(val-la);
        }
        ll digit = A.at(keta)-'0';
        ll ret = INT64_MAX;
        val *= 10;
        ll num = __builtin_popcountll(mask);
        if (num >= K) {
            //新しい数字は使えない
            FOR(i,0,10){
                if(mask&(1<<i)){
                    chmin(ret,dfs(keta+1,val+i,mask));
                }
            }
        } else {
            for(ll i=-1;i<=1;++i){
                ll add = digit + i;
                if(add<0)add+=10;
                chmin(ret, dfs(keta+1, val+add, mask|(1<<add)));
            }
        }
        return ret;
    };
 
    ll ans = dfs(0,0,0);
    cout<<ans<<endl;

    return 0;
}