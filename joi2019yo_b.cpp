//https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_b
//B - すごろくと駒 (Sugoroku and Pieces)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> xn(N+1);
    FOR(i,1,N+1){
        cin>>xn.at(i);
    }
    ll M; cin>>M;
    vector<ll> am(M);
    for(auto&& a:am){
        cin>>a;
    }

    for(const auto& a:am){
        if (xn.at(a)>=2019) {
        } else if (a==xn.size()-1) {
            xn.at(a)++;
        } else if (a<xn.size()-1 && xn.at(a)+1<xn.at(a+1)){
            xn.at(a)++;
        }
    }
    FOR(i,1,N+1){
        cout<<xn.at(i)<<endl;
    }
    return 0;
}