//https://atcoder.jp/contests/abc028/tasks/abc028_d
//D - 乱数生成
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,K; cin>>N>>K;
    //1回
    ll t1=(K-1)*(N-K)*6;
    //2回
    ll t2=(N-1)*3;
    //3回,1
    double r=(double)(t1+t2+1)/(double)(N*N*N);
    cout<<fixed<<std::setprecision(20)<<r<<endl;
    return 0;
}