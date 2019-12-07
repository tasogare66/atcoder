//https://atcoder.jp/contests/cf17-final/tasks/cf17_final_b
//B - Palindrome-phobia
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
    string S; cin>>S;
    vector<ll> abc(3);
    for(const auto c:S){
        ++abc.at(c-'a');
    }
    sort(abc.begin(),abc.end(),greater<ll>());
    auto out_no=[](){
        cout<<"NO"<<endl;exit(0);
    };
    if (abc[1]==0){
        if (abc[0]!=1) out_no();
    }else if (abc[2]==0){
        if(abc[0]!=1||abc[1]!=1)out_no();
    }else{
        if(abc[0]==abc[2] || abc[0]-1==abc[2]){
            //ok
        }else{
            out_no();
        }
    }
    cout<<"YES"<<endl;
    return 0;
}