//https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
//B - Sum AND Subarrays
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
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    dump(an);
    vector<ll> sums(N+1);//累積和
    FOR(i,0,N){
        sums.at(i+1) = sums.at(i)+an.at(i);
    }
    dump(sums);

    //vector<ll> sv;
    //sv.reserve(N*(N+1)/2);
    priority_queue<ll> base;
    FOR(i,0,N){
        FOR(j,i+1,N+1){
            //dump(i,j);
            auto v = sums.at(j)-sums.at(i);
            //sv.push_back(v);
            base.push(v);
        }
    }

    //こっから貪欲.
    auto mx_bit =[](ll v)->ll{
        ll p=0;
        while((1LL<<p)<=v){
            ++p;
        }
        return p;
    };
    ll maxv=base.top();
    ll p=mx_bit(maxv);
    ll tmp=1LL<<p;
    dump(p,tmp);
    ll ans=0;
    for(ll i=p;i>=0;--i){
        ll mask = 1LL<<i;
        ll cnt=0;
        auto pq = base;
        priority_queue<ll> nx;
        while(pq.size()>0){
            auto v = pq.top();
            pq.pop();
            if(v&mask){
                ++cnt;
               nx.push(v); 
            }
        }
        if(cnt>=K){
            base=nx;
            ans |= mask;
        }else{
        }
    }
    cout<<ans<<endl;
    return 0;
}