//https://atcoder.jp/contests/arc013/tasks/arc013_2
//B - 引越しできるかな？
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info{
    ll n=0,m=0,l=0;
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll C; cin>>C;    
    vector<Info> nml(C);
    vector<ll> d3(3);
    Info mx;
    for(auto&& i:nml){
        cin>>d3[0]>>d3[1]>>d3[2];
        sort(d3.begin(),d3.end());
        i.n=d3[0];
        i.m=d3[1];
        i.l=d3[2];
        mx.n=max(mx.n,i.n);
        mx.m=max(mx.m,i.m);
		mx.l=max(mx.l,i.l);
	}
    cout<<mx.n*mx.m*mx.l<<endl;
    return 0;
}