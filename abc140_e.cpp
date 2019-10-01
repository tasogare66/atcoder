//https://atcoder.jp/contests/abc140/tasks/abc140_e
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
    vector<ll> pn(N+1);
    vector<ll> pos(N+1); //aは1..Nを並べ替えたもの
    FOR(i,1,N+1){
        ll p; cin>>p;
        pn.at(i)=p;
        pos.at(p)=i; //場所
    }

    ll ans = 0;
    set<ll> used{0,N+1}; //placeがはいる

    used.insert(pos.at(N)); //Nはいれる
    for(ll v=N-1;v>=1;--v){ //大きいほうから
        auto now_pos=pos.at(v);
        auto it = used.lower_bound(now_pos);
        auto r0 = *it;
        auto r1 = *std::next(it);
        auto l0 = *std::prev(it);
        auto l1 = *std::prev(it,2);
        if (l0>0){
            ans += v*(l0-l1)*(r0-now_pos);
        }
        if (r0<N+1){
            ans += v*(r1-r0)*(now_pos-l0);
        }
        used.insert(now_pos);
    }
    cout<<ans<<endl;
#if 0
    FOR(a,1,N+1){ //aを1から
        auto now_pos=pos[a]; //今の場所
        auto it = used.lower_bound(now_pos); //以上,upper_bound(より上)でもよい
        auto l = *it; //数字が小さい順のplaceを入れていって、その左右をみていく
        auto r = *(--it);
        ans += a*(r-now_pos)*(now_pos-l);
        used.insert(pos[a]);
    }
    cout<<ans<<endl;
#endif
    return 0;
}