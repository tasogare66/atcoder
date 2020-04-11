//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
//Range Sum Query
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}

#include "../fenwick_tree.cpp"

int main() {
    ll n,q; cin>>n>>q;
    fenwick_tree<ll> t(n);
    REP(i,q){
        int c,x,y;
        cin >> c >> x >> y;
        x--;
        if(c == 0) t.add(x,y);
        else cout << t.sum(x,y) << endl;
    }

    return 0;
}