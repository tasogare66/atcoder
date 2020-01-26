//https://atcoder.jp/contests/past201912-open/tasks/past201912_h
//
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
    vector<ll> cn(N+1);

    vector<ll> ans(N+1); //カード単位,売った枚数
    ll ans_all=0, ans_odd=0; //all,oddを売った枚数

    ll min_num_all=INT64_MAX;
    ll min_num_odd=INT64_MAX;

    FOR(i,1,N+1){
        ll c; cin>>c;
        cn.at(i)=c;
        chmin(min_num_all, c);
        if(i%2==1) chmin(min_num_odd, c);
    }
    ll Q; cin>>Q;        
    REP(q,Q){
        ll type; cin>>type;
        if(type==1){
            ll x,a; cin>>x>>a;
            ll cnum = cn.at(x) - ans_all;
            if (x%2==1) cnum -= ans_odd;
            assert(cnum>=0);
            if (cnum >= a) {
                cn[x] -= a;
                ans[x] += a;
                cnum -= a; //次の枚数
                chmin(min_num_all, cnum);
                if(x%2==1) chmin(min_num_odd, cnum);
            }
        }else if(type==2){
            ll a; cin>>a;
            if (min_num_odd >= a){
                min_num_odd -= a;
                min_num_all = min(min_num_all, min_num_odd); //小さい方
                ans_odd += a;
            }
        }else if(type==3){
            ll a; cin>>a;
            if (min_num_all >= a) {
                min_num_all -= a;
                min_num_odd -= a;
                ans_all += a;
            }
        }        
    }

    ll result=0;
    result = accumulate(ans.begin(), ans.end(), 0LL);
    result += (ans_all*N);
    result += ans_odd*((N+1)/2);
    cout<<result<<endl;

    return 0;
}
int main_() { //カード単位で更新だと間に合わない
    ll N; cin>>N;
    vector<ll> cn(N+1);
    ll min_num_all=INT64_MAX;
    ll min_num_odd=INT64_MAX;
    FOR(i,1,N+1){
        ll c; cin>>c;
        cn.at(i)=c;
        chmin(min_num_all, c);
        if(i%2==1) chmin(min_num_odd, c);
    }
    ll Q; cin>>Q;        
    ll ans=0;
    ll ans_all=0;
    ll ans_odd=0;

    auto sell_card = [&](ll x, ll a){
        cn.at(x) -= a;
        assert(cn[x]>=0);
        ans += a;
        chmin(min_num_all, cn[x]);
        if(x%2==1) chmin(min_num_odd, cn[x]);
    };
    auto query1 = [&](ll x, ll a){
        if(cn.at(x)>=a){
            sell_card(x, a);
        }
    };
    auto query2 = [&](ll a){
        if (min_num_odd >= a) {
            for(ll i=1;i<=N;i+=2){
                sell_card(i, a);
            }
        }
    };
    auto query3 = [&](ll a){
        if (min_num_all >= a) {
            FOR(i,1,N+1){
                sell_card(i, a);
            }
        }
    };

    REP(q,Q){
        ll type; cin>>type;
        if(type==1){
            ll x,a; cin>>x>>a;
            query1(x, a);
        }else if(type==2){
            ll a; cin>>a;
            query2(a);
        }else if(type==3){
            ll a; cin>>a;
            query3(a);
        }        
    }
    cout<<ans<<endl;
    return 0;
}