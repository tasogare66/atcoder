//https://atcoder.jp/contests/abc142/tasks/abc142_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<pair<ll,ll>> an(N+1); //no,id
    FOR(i,1,N+1){
        cin>>an.at(i).first;
        an.at(i).second=i;
    }
    sort(an.begin()+1,an.end());

    FOR(i,1,N+1){
        if(i!=1)cout<<" ";
        cout<<an.at(i).second;
    }
    cout<<endl;
    return 0;
}