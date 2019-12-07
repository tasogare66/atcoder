//https://atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_b
//B - ステップカット
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
    ll R,N,M; cin>>R>>N>>M;
    double r=R;
    double unit=2*r/(double)N;
    double ans=0;

    auto calc = [&](ll i)->double{
        double result=0;
        if(i>0&&i<N){
            double a=abs(r-i*unit);
            result = sqrt(r*r - a*a)*2.0;
        }
        return result;
    };

    for(ll i=1;i<=N+M-1;++i){
        ll a=i;
        ll b=i-M;
        ans += max(calc(a),calc(b));
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}