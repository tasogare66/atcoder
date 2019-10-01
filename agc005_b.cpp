//https://atcoder.jp/contests/agc005/tasks/agc005_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main(){
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N+1);
    vector<ll> pos(N+1); //aは1..Nを並べ替えたもの
    FOR(i,1,N+1){
        ll a;
        cin>>a;
        an.at(i)=a;
        pos.at(a)=i; //場所
    }

    ll ans = 0;
    set<ll> used{0,N+1}; //placeがはいる
    //set 追加はO(logN),値はsortされてはいるので、2分探索できる、sortされた順番でiteratorで取得する
    FOR(a,1,N+1){ //aを1から
        auto now_pos=pos[a]; //今の場所
        auto it = used.lower_bound(now_pos); //以上,upper_bound(より上)でもよい
        auto l = *it; //数字が小さい順のplaceを入れていって、その左右をみていく
        auto r = *(--it);
        ans += a*(r-now_pos)*(now_pos-l);
        used.insert(pos[a]);
    }
    cout<<ans<<endl;
    return 0;
}

//tleする
int tle_main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a: an){
        cin>>a;
    }

    ll ans=0;
    for (ll n=N-1;n>=0;--n) {
        ll tmp=INT64_MAX;
        for(ll i=n;i>=0;--i){
            tmp = min(an.at(i), tmp);
            ans += tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}