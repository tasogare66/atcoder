//https://atcoder.jp/contests/arc014/tasks/arc014_2
//B - あの日したしりとりの結果を僕達はまだ知らない。
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
    map<string,ll> tbl;
    auto out_ans = [](ll t){
        cout<<(t%2==1?"WIN":"LOSE")<<endl;
        exit(0); //終わり
    };
    string prev;
    REP(i,N){ //高橋くん先行
        string w; cin>>w;
        if(!prev.empty()){
            if(*prev.rbegin()!=*w.begin()) out_ans(i);
        }
        if(tbl.count(w)) { out_ans(i); }
        tbl[w]=1;
        prev=w;
    }
    cout<<"DRAW"<<endl;
    return 0;
}