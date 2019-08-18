//https://atcoder.jp/contests/abc138/tasks/abc138_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<double> vn(N);
    for(auto&& v:vn){
        cin>>v;
    }
    sort(vn.begin(),vn.end());
    double tmp=(vn[0]+vn[1])/2.0;
    for(ll i=2;i<N;++i){
        tmp=(tmp+vn[i])/2;
    }
    cout<<fixed<<std::setprecision(10)<<tmp<<endl;
    return 0;
}