//https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_b
//B - K個のケーキ / K Cakes
#include <bits/stdc++.h>
using namespace std;
//using ll=int64_t;
using ll=long long int;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
#if 0
    long long int lli;
    long int li;
    int64_t i64t;
    dump(sizeof(long long int));
    dump(sizeof(long int));
    dump(sizeof(int64_t));
    dump(std::is_same<int64_t, long int>::value);
    dump(std::is_same<int64_t, long long int>::value);
    return 0;
#endif
    ll K, T; cin>>K>>T;
    vector<pair<ll,ll>> at(T+1); //数,index
    FOR(i,1,T+1){
        cin>>at.at(i).first;
        at.at(i).second=i;
    }
    sort(at.begin(),at.end(),greater<pair<ll,ll>>());
    ll ans=max(at.begin()->first-1-(K-at.begin()->first),0LL);
    cout<<ans<<endl;
#if 0
    priority_queue<pair<ll,ll>> que;
    FOR(i,1,T+1){
        que.push(at.at(i));
    }

    ll ans=0;
    ll prev=-1;
    REP(i,K){
        auto a=que.top();
        que.pop();
        if(prev!=a.second){
            a.first-=1;
            prev=a.second;
            ++ans;
        }else{
            if(!que.empty()){
                auto b=que.top();
                que.pop();
                if(prev!=b.second){
                    b.first-=1;
                    prev=b.second;
                    ++ans;
                }
                if(b.first>0)que.push(b);
            }
        }
        if(a.first>0)que.push(a);
    }
    cout<<K-ans<<endl;
#endif
    return 0;
}