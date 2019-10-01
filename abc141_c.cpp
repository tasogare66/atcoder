//https://atcoder.jp/contests/abc141/tasks/abc141_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N, K, Q; cin>>N>>K>>Q;    
    vector<ll> point(N+1);
    vector<ll> aq(Q);
    for(auto&& a:aq){
        cin>>a;
        point.at(a)++;
    }
    for(auto&& p:point){
        p=K+p-Q;
    }
    FOR(i,1,point.size()){
        if(point[i]<=0){
            cout<<"No"<<endl;
        }else {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}