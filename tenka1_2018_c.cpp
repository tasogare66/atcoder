//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
//C - Align
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
    ll N; cin>>N;
    deque<ll> an(N);
    deque<ll> orig_an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    orig_an=an;

    auto getpop_back = [&]()->ll{
        ll r=-1;
        if(!an.empty()){
            r=*(an.end()-1);
            an.pop_back();
        }
        return r;
    };
    auto getpop_front = [&]()->ll{
        ll r=-1;
        if(!an.empty()){
            r=*an.begin();
            an.pop_front();
        }
        return r;
    };

    deque<ll> res;
    res.push_back(getpop_front());

    bool back_flag=true; //backから
    while(!an.empty()){
        ll a=-1,b=-1;
        if (back_flag){
            a=getpop_back();
            b=getpop_back();
        }else{
            a=getpop_front();
            b=getpop_front();
        }
        if (a>=0) res.push_front(a);
        if (b>=0) res.push_back(b);

        back_flag = !back_flag;
    }
    ll ans=0;
    FOR(i,1,res.size()){
        ans += abs(res.at(i)-res.at(i-1));
    }
    dump(res);
    dump(ans);

    //もう一回?
    an=orig_an;
    deque<ll> res2;
    res2.push_back(getpop_back());
    back_flag=false; //frontから
    while(!an.empty()){
        ll a=-1,b=-1;
        if (back_flag){
            a=getpop_back();
            b=getpop_back();
        }else{
            a=getpop_front();
            b=getpop_front();
        }
        if (a>=0) res2.push_front(a);
        if (b>=0) res2.push_back(b);

        back_flag = !back_flag;
    }
    ll ans2 = 0;
        FOR(i,1,res2.size()){
        ans2 += abs(res2.at(i)-res2.at(i-1));
    }
    dump(res2);
    dump(ans2);

    cout<<max(ans,ans2)<<endl;

    return 0;
}
