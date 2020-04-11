//https://atcoder.jp/contests/abc158/tasks/abc158_c
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
int main(){
    ll A,B; cin>>A>>B;
    ll val=1;
    FOR(i,1,1000000){
        float fi=i;
        float aa=i*0.08;
        ll ia=aa;

        float bb=i*0.1;
        ll ib=bb;
        if(ia==A&&ib==B){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}


int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B; cin>>A>>B;
    float aa=(float)A/0.08;
    float bb=(float)B/0.10;    
    dump(aa,bb);

    ll ans=-1;
    FOR(i,aa,aa+100){
        float vi=(float)i*0.08;
        ll va=vi;
        dump(i,va);
        if(va!=A)break;
        FOR(j,bb,bb+100){
            float vj=(float)j*0.1;
            ll vb=vj;
            dump(j,vb);
            if(vb!=B)break;

            if(i==j){
                ans=min(ans,i);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}