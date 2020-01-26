//https://atcoder.jp/contests/arc053/tasks/arc053_b
//B - 回文分割
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
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string S; cin>>S;
    unordered_map<char,ll> tbl;
    for(const auto& c:S){
        tbl[c]++;
    }
    vector<ll> cnt;
    for(const auto& it :tbl){
        cnt.push_back(it.second);
    }
    sort(cnt.begin(),cnt.end());
    priority_queue<ll, vector<ll>, greater<ll> > queue;
    for(auto&& v:cnt){
        if(v%2==1){
            queue.push(1);
            --v;
        }
    }
    if(queue.empty()){
        queue.push(0);
    }
    sort(cnt.begin(),cnt.end());    
    for(auto&& v:cnt){
        while(v>0){
            v-=2;
            auto qv = queue.top();
            queue.pop();
            qv+=2;
            queue.push(qv);
        }

    }
    ll ans=INT64_MAX;
    while(queue.size()>0){
        ans = min(ans,queue.top());
        queue.pop();
    }
    cout<<ans<<endl;
    return 0;
}