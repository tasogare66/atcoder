//https://atcoder.jp/contests/abc053/tasks/arc068_b
//左右からはさんでカウントしていく
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    ll l=0, r=an.size()-1;
    auto check_idx = [&](ll v){
        return (v>=0 && v < an.size());
    };
    auto func_step = [&](ll &v,ll di){
        while(true){
			auto v0 = v;
			auto v1 = v + di;
            if (!check_idx(v0) || !check_idx(v1)) return;
			if(an.at(v0) == an.at(v1)) {
				return; //同じだったら戻る
			}
            v=v1;
		}
    };
    ll ans=0;
    while(true){
        // lrを移動
        func_step(l,1);
        func_step(r,-1);
        if (l>=r) break;
        if (r-l==1) {ans+=2;break;}
        ans+=2;
        ++l;
        --r;
        if (l>=r) break;
    }
    cout<<(an.size()-ans)<<endl;
    return 0;
}