//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c
//C - Ordinary Beauty
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
void test(){
    ll sum=0;
    FOR(i,1,3) FOR(j,1,3) FOR(k,1,3) FOR(l,1,3){
        vector<ll> tbl={
            i,j,k,l
        };
        FOR(p,1,tbl.size()){
            if(abs(tbl[p]-tbl[p-1])==1){
                ++sum;
            }
        }
    }
    double r=(double)sum/16.0;
    dump(sum,r);
}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
#if LOCAL
    test();
#endif
    ll n,m,d; cin>>n>>m>>d;
    ll sc=0;
    sc += (n-d);
    if(d!=0)sc*=2;
    double r1=(double)sc/(double)(n*n);
    dump(r1);
    double ans=r1*(double)(m-1);
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}